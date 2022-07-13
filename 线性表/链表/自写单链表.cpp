typedef struct LNode{
    int val;
    struct LNode *next;
    LNode() : val(0), next(nullptr) {}
    LNode(int v) : val(v), next(nullptr) {}
    LNode(int v,struct LNode *x) : val(v), next(x) {}
}LNode, *linkedList;

class MyLinkedList {
    struct LNode *head;     //默认为private私有成员
    int size;               //默认为private私有成员

public:
    MyLinkedList() {
        head = new LNode();
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        linkedList L = head;
        for(int i=0;i<index+1;i++)
            L = L->next;
        return L->val;
    }
    
    void addAtHead(int val) {
        linkedList s = new LNode(val);
        s->next = head->next;
        head->next = s;
        size++;
    }
    
    void addAtTail(int val) {
        linkedList s = head;
        for(int i=0;i<size;i++)
            s = s->next;
        s->next = new LNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        linkedList s = head;
        if(index<0)
            addAtHead(val);
        else if(index==size)
            addAtTail(val);
        else if(index>size)
            return;
        else{
            for(int i=0;i<index;i++)
                s = s->next;
            linkedList newNode = new LNode(val);
            newNode->next = s->next;
            s->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size || size==0)
            return;
        linkedList s = head;
        for(int i=0;i<index;i++)
            s = s->next;
        linkedList nextNode = s->next;
        s->next = nextNode->next;
        delete nextNode;
        size--;
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
