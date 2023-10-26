#include <iostream>

template<typename T, int capacity=10>
class SequenceList
{
private:
    int _size;
    T _array[capacity];

public:
    SequenceList():_size(0){};
    ~SequenceList(){};
    int get_capacity();
    int size();
    T get(int i);
    int locate(T value);
    bool insert(T value, int i);
    SequenceList& append(T value);
    bool remove(T value);

    void show();
};

template<typename T, int capacity>
int SequenceList<T, capacity>::get_capacity()
{
    return capacity;
}

template<typename T, int capacity>
int SequenceList<T, capacity>::size()
{
    return _size;
}

template<typename T, int capacity>
T SequenceList<T, capacity>::get(int i)
{
    if (i < 0 || i > _size-1)
        throw "index exceed range!";
    return _array[i];
}

template<typename T, int capacity>
int SequenceList<T, capacity>::locate(T value)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template<typename T, int capacity>
bool SequenceList<T, capacity>::insert(T value, int i)
{
    if (_size == capacity)
        return false;

    if (i < 0 || i > _size)
        return false;

    for (int j = _size; j > i; --j)
    {
        _array[j] = _array[j-1];
    }
    _array[i] = value;

    _size++;
    return true;
}

template<typename T, int capacity>
SequenceList<T, capacity>& SequenceList<T, capacity>::append(T value)
{
    insert(value, _size);

    return *this;
}

template<typename T, int capacity>
bool SequenceList<T, capacity>::remove(T value)
{
    int idx = locate(value);
    if (idx == -1)
        return false;

    for (int i = idx; i < _size-1; ++i)
    {
        _array[i] = _array[i+1];
    }

    _size--;
    return true;
}


template<typename T, int capacity>
void SequenceList<T, capacity>::show()
{
    std::cout << "size[" << _size << "]: ";
    for (int i = 0; i < _size; ++i)
    {
        std::cout << _array[i] << " -> ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{

    SequenceList<int> sl;

    std::cout << "sl's capacity = " << sl.get_capacity() << std::endl;

    sl.append(1).append(2).append(3).append(4);
    sl.show();

    sl.insert(10, 2);
    sl.insert(20, sl.size());
    sl.show();

    std::cout << "20's locate = " << sl.locate(20) << ", 30's locate = " << sl.locate(30) << std::endl;

    sl.remove(4);
    sl.remove(20);
    sl.show();

    std::cout << "get(1) = " << sl.get(1) << std::endl;

    try
    {
        sl.get(10);
    }
    catch (const char *exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}
