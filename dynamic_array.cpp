#include <stdlib.h>
#include <utility>
#include <iostream>

const int MIN_CAPACITY = 8;
const int GROWING_FACTOR = 2;

template <class T>
class Array final
{
public:
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
        T* placement_new = new (_array + _count_of_elements) T(value);
        // *(_array + _count_of_elements) = value;
        _count_of_elements++;
    }

    void insert(int index, const T& value) {
        if (_count_of_elements == _array_capacity || index >= _array_capacity)
            resize();

        if (index < _count_of_elements)
        {
            for (int i = _count_of_elements; i > index; i--)
            {
                // *(_array + i + 1) = *(_array + i);
                // _array + i = nullptr;
                // *(_array + i + 1) = std::move(*(_array + i));
                T* placement_new = new (_array + i) T(*(_array + i));
                *(_array + i + 1) = *(placement_new);
                placement_new->~T();
            }
            T* placement_new = new (_array + index) T(value);
            _count_of_elements++;
        }else
        {
            if (index > _count_of_elements)
            {
                T* placement_new = new (_array + index) T(value);
                _count_of_elements += index -_count_of_elements + 1;
            }else
            {
                insert(value);
            }
            
        }
    }

    void remove(int index) {
        if (index <= _count_of_elements && index >= _count_of_elements)
        {
            T* placement_new = new (_array + index) T();
            placement_new->~T();
            for (int i = index + 1; i < _count_of_elements; i++)
            {
                *(_array + index) = std::move(*(_array + index));
            }
            
        }
    }
// TEST METHODS
    void test_resize() {
        resize();
    }

    void testm_print() {
        for (int i = 0; i < _array_capacity; i++)
        {
            std::cout << *(_array + i) << " ";
        }
        std::cout << std::endl;
    }

private:
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
        // DEBUG START
        // std::cout << "temp arra befor initialize" << std::endl;
        // for (int i = 0; i < capacity; i++)
        // {
        //     std::cout << *(temp_array + i) << " ";
        // }
        // DEBUG END
        
        // std::cout << std::endl;
        for (int i = 0; i < _count_of_elements; i++)
        {
            T* placement_new = new (temp_array + i) T(*(_array + i));
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

        // T* peek = _array;
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