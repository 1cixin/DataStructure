struct Listnode
{
    int val;
    struct Listnode *prev;
    struct Listnode *next;
    Listnode() : val(0), prev(nullptr), next(nullptr) {}
    Listnode(int v) : val(v), prev(nullptr), next(nullptr) {}
    Listnode(int v, Listnode *p) : val(v), prev(p), next(nullptr) {}
    Listnode(int v, Listnode *p, Listnode *n) : val(v), prev(p), next(n) {}
};

class MyLinkedList
{
    int size;
    Listnode *head;
    Listnode *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        size = 0;
        head = new Listnode(0);
        tail = new Listnode(0);
        head->next = tail;
        tail->prev = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        Listnode *trav = head;
        if (index + 1 < size - index)
        {
            for (int i = 0; i < index + 1; ++i)
                trav = trav->next;
        }
        else
        {
            trav = tail;
            for (int i = 0; i < size - index; ++i)
                trav = trav->prev;
        }
        return trav->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Listnode *newNode = new Listnode(val, head, head->next);
        newNode->next->prev = newNode;
        head->next = newNode;
        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Listnode *newNode = new Listnode(val, tail->prev, tail);
        tail->prev->next = newNode;
        tail->prev = newNode;
        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        Listnode *trav = head;
        if (index + 1 < size - index)
        {
            for (int i = 0; i < index + 1; ++i)
                trav = trav->next;
        }
        else
        {
            trav = tail;
            for (int i = 0; i < size - index; ++i)
                trav = trav->prev;
        }
        Listnode *newNode = new Listnode(val, trav->prev, trav);
        trav->prev->next = newNode;
        trav->prev = newNode;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        Listnode *trav = head;
        if (index + 1 < size - index)
        {
            for (int i = 0; i < index + 1; ++i)
                trav = trav->next;
        }
        else
        {
            trav = tail;
            for (int i = 0; i < size - index; ++i)
                trav = trav->prev;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        delete trav;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


作者：Roycec
链接：https://leetcode.cn/problems/design-linked-list/solution/707-she-ji-lian-biao-by-roycec-ywx9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
