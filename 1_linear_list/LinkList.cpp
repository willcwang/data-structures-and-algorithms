#include <iostream>

template<typename T>
class LinkNode
{
    public:
    T value;
    LinkNode *next;

    LinkNode():next(nullptr){};
    LinkNode(T val):value(val), next(nullptr){};
    ~LinkNode(){
        std::cout << "run ~LinkNode" << std::endl;
    }
};

template<typename T>
class LinkList
{
    private:
    int _size = 0;

    public:
    LinkNode<T> *head;

    LinkList():head(nullptr),_size(0){}
    ~LinkList();

    public:
    LinkList& append(T value);
    void show();
    int size(){return _size;}
    bool empty(){return _size == 0;}
};

template<typename T>
LinkList<T>::~LinkList()
{
    LinkNode<T> *node = head;
    LinkNode<T> *tmp = nullptr;
    while (node != nullptr)
    {
        tmp = node;
        node = node->next;
        delete tmp;
    }
}

template<typename T>
void LinkList<T>::show()
{
    LinkNode<T> *node = head;
    while (node != nullptr)
    {
        node = node -> next;
    }
    std::cout << std::endl;
}

template<typename T>
LinkList<T>& LinkList<T>::append(T value)
{
    LinkNode<T> *pnode = new LinkNode<T>(value);
  
    if (head == nullptr)
    {
        head = pnode;
        _size++;
        return *this;
    }

    LinkNode<T> *node = head;
    while (node -> next != nullptr)
    {
        node = node -> next;
    }
    node -> next = pnode;
    _size++;

    return *this;
}

int main()
{
    LinkList<int> ll;
    ll.append(1).append(2).append(3).append(4);
    if (!ll.empty())
        ll.show();

    return 0;
}
