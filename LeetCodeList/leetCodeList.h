#ifndef LEETCODELIST
#define LEETCODELIST

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node() {}
    Node(T t)
        : data(t)
        , next(nullptr) {}
};

typedef Node<int> ListNodeInt;

template<typename T>
class ListNode
{
    typedef Node<T>     list_node;
    typedef list_node*  link_type;
public:
    ListNode()
    {
        head = new list_node;
        head->next = nullptr;
    }

    ~ListNode()
    {
        link_type temp = head;
        if (head != nullptr) {
            delete head;
            head = nullptr;
        }
    }

    void insert(T val)
    {
        link_type n = new list_node;
        n->data = val;
        n->next = head->next;
        head->next = n;
    }

public:
    Node<T>* head;
};

#endif // LEETCODELIST

