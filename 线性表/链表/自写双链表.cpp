typedef struct DNode{
    int val;
    struct DNode *prior,*next;
    DNode() : val(0), prior(nullptr), next(nullptr) {}
    DNode(int x) : val(x), prior(nullptr), next(nullptr) {}
}DNode, *DLinklist;

class MyLinkedList {
    struct DNode *head;
    int size;
public:
    MyLinkedList() {
        head = new DNode();
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        DLinklist s = head;
        for(int i=0;i<index+1;i++)
            s = s->next;
        return s->val;
    }
    
    void addAtHead(int val) {
        DLinklist s = new DNode(val);
        s->next = head->next;
        s->prior = head;
        if(head->next!=nullptr)     //head->next->prior之前记得判断
            head->next->prior = s;
        head->next = s;
        size++;
    }
    
    void addAtTail(int val) {
        DLinklist s = head;
        for(int i=0;i<size;i++)
            s = s->next;
        DLinklist tailNode = new DNode(val);
        s->next = tailNode;
        tailNode->prior = s;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        else if(index<0)
            addAtHead(val);
        else if(index==size)
            addAtTail(val);
        else{
            DLinklist s = head;
            for(int i=0;i<index;i++)
                s = s->next;
            DLinklist cur = new DNode(val);
            cur->next = s->next;
            s->next->prior = cur;
            s->next = cur;
            cur->prior = s;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size || size==0)
            return;
        DLinklist s = head;
        for(int i=0;i<index+1;i++)
            s = s->next;
        if(s->next!=nullptr)     //head->next->prior之前记得判断
            s->next->prior = s->prior;
        s->prior->next = s->next;
        delete s;
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
