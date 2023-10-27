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
    bool insert(T value, int i);
    bool remove(int i);
};

template<typename T>
bool LinkList<T>::remove(int i)
{
    if (i < 0 || i > _size-1)
    {
        return false;
    }
    LinkNode<T> *tmp = nullptr;
    if (i == 0)
    {
        tmp = head;
        head = head->next;
        delete tmp;
        _size--;
        return true;
    }

    LinkNode<T> *node = head;
    for (int j = 0; j < i-1; ++j)
    {
        node = node->next;
    }
    tmp = node->next;
    node->next = tmp->next;
    delete tmp;
    _size--;

    return true;
}

template<typename T>
bool LinkList<T>::insert(T value, int i)
{
    if (i < 0 || i > _size)
    {
        return false;
    }
    LinkNode<T> *insert_node = new LinkNode<T>(value);
    if (i == 0)
    {
        insert_node->next = head;
        head = insert_node;
        _size++;
        return true;
    }
    LinkNode<T> *node = head;
    for (int j = 0; j < i-1; ++j)
    {
        node = node->next;
    }
    insert_node->next = node->next;
    node->next = insert_node;
    _size++;
    return true;
}

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

    ll.insert(10, 3);
    ll.insert(20, 1);
    ll.insert(30, 0);
    ll.insert(40, 7);
    ll.show();

    ll.remove(7);
    ll.remove(0);
    ll.show();

    return 0;
}
