#include <iostream>

template<typename T>
class SeqStack
{
    private:
    T *pbase;
    T *ptop;
    int size;

    public:
    SeqStack(){
        size = 2;
        pbase = new T[2];
        ptop = pbase;
    }
    ~SeqStack(){
        delete[] pbase;
        pbase = ptop = nullptr;
        size = 0;
        std::cout << "~SeqStack run!" << std::endl;
    }

    // 移动赋值
    

    int expand();
    int getSize(){return size;}

    bool is_empty(){return pbase == ptop;}
    int push(const T &value);
    int pop();
    T& top();
};

template<typename T>
int SeqStack<T>::expand()
{
    T *new_base = new T[size * 2];

    for (int i = 0; i < size; ++i)
    {
        new_base[i] = *(pbase + i);
    }

    delete[] pbase;
    ptop = new_base + size;
    pbase = new_base;

    return size*=2;
}

template<typename T>
int SeqStack<T>::push(const T &value)
{
    if ((ptop - pbase) == size)
    {
        expand();
    }
    *(++ptop) = value;

    return size;
}

template<typename T>
int SeqStack<T>::pop()
{

    return *(--ptop);
}

template<typename T>
T& SeqStack<T>::top()
{
    if (pbase == ptop)
    {
        throw "stack is empty!";
    }
    return *ptop;
}


int main()
{
    SeqStack<int> stack;

    std::cout << "size = " << stack.getSize() << std::endl;

    stack.push(1);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;
    stack.push(2);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;

    stack.push(3);
    stack.push(4);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;

    stack.push(5);
    stack.push(6);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;

    stack.pop();
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;

    stack.push(6);
    stack.push(7);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;
    stack.push(8);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;
    stack.push(9);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;
    stack.push(10);
    stack.push(11);
    stack.push(12);
    std::cout << "size = " << stack.getSize() << ", top = " << stack.top() <<  std::endl;

    std::cout << "============ end =============" << std::endl;
}
