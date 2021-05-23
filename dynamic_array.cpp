#include <stdlib.h>
#include <utility>
// #include <iostream>

const int MIN_CAPACITY = 8;
const int GROWING_FACTOR = 2;

template <class T>
class Array final
{
public:
    class Iterator {

    public:
        Iterator(Array* array_class) {
            _array_class = array_class;
            _position = 0;
        }

        const T& get() const {
            return *(_array_class->_array + _position);
        }

        void set(const T& value) {
            _array_class->_array[_position] = value;
        }

        void insert(const T& value) {
            _array_class->insert(_position, value);
        }

        void remove() {
            _array_class->remove(_position);
        }

        void next() {
            _position++;
        }

        void prev() {
            _position--;
        }
        
        void toIndex(int index) {
            _position = index;
        }

        bool hasNext() const {
            return _array_class->size() > _position;
        }

        bool  hasPrev() const {
            return _position != 0;
        }

    private:
        int _position;
        Array * _array_class;
    };

    Array() {
        _array_capacity = MIN_CAPACITY;
        _array = (T*)malloc(_array_capacity * sizeof(*_array));
        _count_of_elements = 0;
    }

    Array(int size) {
        _array_capacity = size;
        _array = (T*)malloc(_array_capacity * sizeof(*_array));
        _count_of_elements = 0;
    }

    ~Array() {
        free(_array);
    }

    void insert(const T& value) {
        if (_count_of_elements >= _array_capacity)
            resize();
        new (_array + _count_of_elements) T(std::move(value));
        // *(_array + _count_of_elements) = value;
        _count_of_elements++;
    }

// Убрать часть с тем что можно втавлять значения по индексу которые больше капасити
    void insert(int index, const T& value) {
        if (_count_of_elements == _array_capacity || index >= _array_capacity)
            resize();

        if (index < _count_of_elements)
        {
            for (int i = _count_of_elements; i > index; i--)
            {
                // std::cout << "in insert " << std::endl;
                new (_array + i) T(std::move(*(_array + i - 1)));
            }
            // TODO Убрать move 
            new (_array + index) T(std::move(value));
            _count_of_elements++;

        }
        else {
            if (index > _count_of_elements)
            {
                new (_array + index) T(std::move(value));
                _count_of_elements += index -_count_of_elements + 1;
            }else
            {
                insert(value);
            }
        }
    }

    void remove(int index) {
        if (index <= _count_of_elements && !(index >= _count_of_elements))
        {
            // std::cout << "remove" << std::endl;
            // T* placement_new = new (_array + index) T();
            // placement_new->~T();
            (_array + index)->~T();


            for (int i = index; i < _count_of_elements - 1; i++)
            {
                // std::cout << "in remove loop" << std::endl;
                 
                new (_array + i) T(std::move(*(_array + i + 1)));
                // *(_array + i) = *(_array + i + 1);
                
                // new (_array + i + 1) T();
            }
            _count_of_elements--;
        }
    }

    int size() const {
        return _count_of_elements;
    }

    const T& operator[](int index) const {
        return *(_array + index);
    }

    T& operator[](int index) {
        return *(_array + index);
    }

    Iterator iterator() {
        return Iterator(this);
    }
    const Iterator iterator() const {
        return Iterator(this);
    }

private:
    // Запрещение копирования
    Array(const Array&);
    // Запрещение копирования
    Array& operator=(const Array&);
    // Количество реально существующих элементов в массиве
    int _count_of_elements;
    // Количество элементов возможных для заполнения в массиве
    int _array_capacity;
    // Указатель на начало выделенного массива
    T *_array;

    void resize() {
        // memmove не использовать его
        // вместо этого использовать
        // sdt::move()
        int capacity = _array_capacity * GROWING_FACTOR;
        // _array = (T*)realloc(_array, _array_capacity * sizeof(*_array));
        // T* temp_array = (T*)realloc(_array, _array_capacity * sizeof(*_array));
        // _array = std::move(temp_array);
        // temp_array = std::move(_array);
        // _array = std::move(temp_array);
        T* temp_array = (T*)malloc(capacity * sizeof(*_array));

        // std::cout << "temp_array " << *(temp_array) << std::endl;

        // DEBUG START
        // std::cout << "temp arra befor initialize" << std::endl;
        // for (int i = 0; i < capacity; i++)
        // {
        //     std::cout << *(temp_array + i) << " ";
        // }
        // DEBUG END

        // T* peek = _array;
        // std::cout << "Before free and before move" << std::endl;
        // for (int i = 0; i < _array_capacity; i++)
        // {
        //     std::cout << *(peek + i) << " ";
        // }
        // std::cout << std::endl;
        
        // std::cout << std::endl;
        for (int i = 0; i < _count_of_elements; i++)
        {
            // move_test(temp_array + i, _array + i);
            new (temp_array + i) T(std::move(*(_array + i)));

            // T* placement_new = new (temp_array + i) T(*(_array + i));

            // (temp_array + i)->~T();
            // TEST START Placement new and copy constructor
            // T* placement_new = new (temp_array + i) T();
            // T* old_item = _array + i;
            // *placement_new = *(old_item);
            // old_item->~T();
            // TEST END
            
            // *(temp_array + i) = *(_array + i);
        }
        // DEBUG START
        // std::cout << "Pointer(temp_array) before = operator" << std::endl;
        // std::cout << temp_array << std::endl;
        // // DEBUG END

        // // DEBUG START
        // std::cout << "Pointer(array) before = operator" << std::endl;
        // std::cout << _array << std::endl;
        // // DEBUG END

        // std::cout << "Before free" << std::endl;
        // for (int i = 0; i < _array_capacity; i++)
        // {
        //     std::cout << *(peek + i) << " ";
        // }
        // std::cout << std::endl;

        free(_array);

        // std::cout << "After free" << std::endl;
        // for (int i = 0; i < _array_capacity; i++)
        // {
        //     std::cout << *(peek + i) << " ";
        // }
        // std::cout << std::endl;

        _array = temp_array;
        // free(temp_array);
        
        // DEBUG START
        // std::cout << "Pointer(temp_array) after = operator" << std::endl;
        // std::cout << temp_array << std::endl;
        // // DEBUG END

        // std::cout << "Pointer(array) after = operator" << std::endl;
        // std::cout << _array << std::endl;

        // DEBUG START
        // std::cout << "temp arra after move" << std::endl;
        // for (int i = 0; i < capacity; i++)
        // {
        //     std::cout << *(temp_array + i) << " ";
        // }
        // DEBUG END

        _array_capacity = capacity;
    }
};