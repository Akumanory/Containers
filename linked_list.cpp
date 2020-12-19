#include <utility>
#include <iostream>

// Сделать около 14
// const int ARRAY_CAPACITY;

#define CHUNK_SIZE(x) (sizeof(Chunk) + (sizeof(T) * ((x) - 1)))
// #define CHUNK_SIZE(x) (sizeof(Chunk) + (sizeof(T) * x))

template<typename T>
class Unrolled_List final
{
public:
    struct Chunk
    {
        int elements_in_chunk = 0;
        struct Chunk* next;
        struct Chunk* prev;
        // 24 - sizeod(Chunk) - пока не знаю как по красивие сделать потому 
        // что если создавать новую переменную то размер чанка выйдет за отметку 24
        // 64 размер кеш линии
        T data[1];
    };

    class Iterator {

    public:
        Iterator(Unrolled_List* list_class) {
            _list_class = list_class;
            _start_from_head = _list_class->_head;
            _position = 0;
        }

        const T& get() const {
            return _start_from_head->data[_position];
        }

        void set(const T& value) {
            _start_from_head->data[_position] = value;
        }

        void insert(const T& value) {
            std::cout << "elements_in_chunk " << _start_from_head->elements_in_chunk << std::endl;
            std::cout << "_array_capacity_of_chunk " << _list_class->_array_capacity_of_chunk << std::endl;
            if (_start_from_head->elements_in_chunk == _list_class->_array_capacity_of_chunk)
            {
                Chunk* new_chunk = (Chunk *)malloc(CHUNK_SIZE(_list_class->_array_capacity_of_chunk));
                if (_start_from_head == _list_class->_tail)
                {
                    _list_class->_tail = new_chunk;
                }
                new_chunk->next = _start_from_head->next;
                _start_from_head->next = new_chunk;
                new_chunk->prev = _start_from_head;
                new_chunk->elements_in_chunk = 1;
                if (_start_from_head->elements_in_chunk - 1 == _position)
                {
                    new (new_chunk->data) T(std::move(value));
                }
                else
                {
                    new (new_chunk->data) T(std::move(_start_from_head->data[_list_class->_array_capacity_of_chunk - 1]));
                    for (int i = _list_class->_array_capacity_of_chunk - 1; i > _position; i--)
                    {
                        new (_start_from_head->data + i + 1) T(std::move(_start_from_head->data[i]));
                        // std::cout << "I: " << i << std::endl;
                    }
                    new (_start_from_head->data + _position + 1) T(std::move(value));
                }
            }
            else
            {
                _start_from_head->elements_in_chunk += 1;
                for (int i = _list_class->_array_capacity_of_chunk - 1; i > _position; i--)
                {
                    new (_start_from_head->data + i + 1) T(std::move(_start_from_head->data[i]));
                    std::cout << "I: " << i << std::endl;
                }
                new (_start_from_head->data + _position + 1) T(std::move(value));
            }
        }

        void remove() {
            if (_start_from_head == _list_class->_tail 
            && _start_from_head == _list_class->_head 
            && _start_from_head->elements_in_chunk == 1)
            {
                // _start_from_head->data[0]->~T();
                _start_from_head->elements_in_chunk == 0;
            }
            else
            {
                //Не забыть что уменьшаю здесь здесь
                _start_from_head->elements_in_chunk -= 1;
                if (_start_from_head->elements_in_chunk == 0)
                {
                    if (_start_from_head==_list_class->_tail)
                    {
                        _list_class->_tail == _start_from_head->prev;
                        auto temp = _start_from_head;
                        _start_from_head == _start_from_head->prev;
                        free(temp);
                    }
                    else
                    {
                        auto temp = _start_from_head;
                        auto next_temp = _start_from_head->next;
                        auto prev_temp = _start_from_head->prev;

                        next_temp->prev = prev_temp-> next;

                        _start_from_head = _start_from_head->next;
                        free(temp);
                    }
                }else
                {
                    if (_position != _start_from_head->elements_in_chunk)
                    {
                        for (int i = _position; i < _start_from_head->elements_in_chunk; i++)
                        {
                            new (_start_from_head->data + i) T(std::move(_start_from_head->data[i + 1]));
                        }
                    }else
                    {
                        _position -= 1;
                    }
                }
            }
        }

        void next() {
            _position++;
            if (_start_from_head->elements_in_chunk == _position && _start_from_head != _list_class->_tail)
            {
                _position = 0;
                _start_from_head = _start_from_head->next;
                std::cout << "To Another Chunk" << std::endl;
            }
        }

        void prev() {
            _position--;
            if (_position == 0 && _start_from_head != _list_class->_tail)
            {
                _position = _start_from_head->elements_in_chunk;
                _start_from_head = _start_from_head->prev;
                std::cout << "To Another Chunk" << std::endl;
            }
        }

        bool hasNext() const {
            std::cout << "pos hasNext: " << _position << std::endl;
            if (_start_from_head == _list_class->_tail && _start_from_head->elements_in_chunk == _position)
            {
                return false;
            }
            return true;
        }

        bool  hasPrev() const {
            std::cout << "pos hasNext: " << _position << std::endl;
            if (_start_from_head == _list_class->_head && _position == 0)
            {
                return false;
            }
            return true;
        }

    private:
        Chunk* _start_from_head;
        int _position;
        Unrolled_List * _list_class;
    };

    Unrolled_List() {
        std::cout << "sizeof(T) " << sizeof(T) << std::endl;
        std::cout << "sizeof(Chunk) " << sizeof(Chunk) - sizeof(T) << std::endl;
        std::cout << "count of elements for size of " << 40 / sizeof(T) << std::endl;
        // _array_capacity_of_chunk = (64 - sizeof(Chunk)) / sizeof(T);
        // ARRAY_CAPACITY = (64 - 24) / sizeof(T);
        // _list = new Chunk(_array_capacity_of_chunk);
        _array_capacity_of_chunk = (64 - sizeof(Chunk) + sizeof(T)) / sizeof(T);
        std::cout << "elements " << _array_capacity_of_chunk << std::endl;
        _list = (Chunk *)malloc(CHUNK_SIZE(_array_capacity_of_chunk));
        std::cout << "size of list " << sizeof(*_list) << std::endl;
        _count_of_elements = 0;
        _head = _list;
        _tail = _list;
        std::cout << "_head " << _head << std::endl;
        std::cout << "_tail " << _tail << std::endl;
        if (_head == _tail)
        {
            std::cout << "_tail and _head equal" << std::endl;
        }
        
    }

    ~Unrolled_List() {
        std::cout << "_head " << _head << std::endl;
        std::cout << "_tail " << _tail << std::endl;
        while (_head != _tail)
        {
            std::cout << "_head " << _head << std::endl;
            std::cout << "_tail " << _tail << std::endl;
            Chunk * temp = _head;
            _head = _head->next;
            free(temp);
        }
        free(_head);
    }

    void insertHead(const T& value) {
        if (_head->elements_in_chunk == _array_capacity_of_chunk)
        {
            auto temp =_head;
            _head = (Chunk *)malloc(CHUNK_SIZE(_array_capacity_of_chunk));
            temp->prev = _head;
            _head->next = temp;
        }
        T* ptr = _head->data;
        new (ptr + _head->elements_in_chunk) T(std::move(value));
        _head->elements_in_chunk += 1;
        _count_of_elements++;
    }

    void insertTail(const T& value) {
        if (_tail->elements_in_chunk == _array_capacity_of_chunk)
        {
            auto temp =_tail;
            _tail = (Chunk *)malloc(CHUNK_SIZE(_array_capacity_of_chunk));
            temp->next = _tail;
            _tail->prev = temp;
        }
        T* ptr = _tail->data;
        new (ptr + _tail->elements_in_chunk) T(std::move(value));
        _tail->elements_in_chunk += 1;
        _count_of_elements++;
    }

    void removeHead() {
        if (_head->elements_in_chunk == 1)
        {
            Chunk * temp = _head;
            _head = _head->next;
            _head->prev = NULL;
            free(temp);
        }else
        {
            _head->elements_in_chunk -= 1;
        }
        _count_of_elements--;
    }

    void removeTail() {
        if (_tail->elements_in_chunk == 1)
        {
            Chunk * temp = _tail;
            _tail = _tail->prev;
            _tail->next = NULL;
            free(temp);
        }else
        {
            _tail->elements_in_chunk -= 1;
        }
        _count_of_elements--;
    }

    const T& head() const {
        return _head->data[0];
    }

    const T& tail() const{
        return _tail->data[_tail->elements_in_chunk - 1];
    }

    int size() const {
        return _count_of_elements;
    }

    Iterator iterator() {
        return Iterator(this);
    }
    const Iterator iterator() const {
        return Iterator(this);
    }

    // TEST METHODS
    void print_head_chunk() {
        std::cout << "print_head_chunk" << std::endl;
        T* array = _head->data;
        for (int i = 0; i < _head->elements_in_chunk; i++)
        {
            std::cout << *(array + i) << " " << std::endl;
        }
    }

    void print_tail_chunk() {
        std::cout << "print_tail_chunk" << std::endl;
        T* array = _tail->data;
        for (int i = 0; i < _tail->elements_in_chunk; i++)
        {
            std::cout << *(array + i) << " " << std::endl;
        }
        
    }

private:
    // Запрещение копирования
    Unrolled_List(const Unrolled_List&);
    // Запрещение копирования
    Unrolled_List& operator=(const Unrolled_List&);

    Chunk * _head;
    Chunk * _tail;
    Chunk * _list;
    int _array_capacity_of_chunk;
    int _count_of_elements;
};