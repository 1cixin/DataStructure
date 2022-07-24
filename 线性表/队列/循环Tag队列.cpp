class MyCircularQueue {
    vector<int> data;
    int front,rear;
    int MaxSize;
    int tag;            //区别队空，进队就1，出队就0，配合front==rear判断是否空。
public:
    MyCircularQueue(int k) {
        data = vector<int>(k);
        front = rear = 0;
        MaxSize = k;
        tag = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())  return false;
        data[rear] = value;
        rear = (rear+1)%MaxSize;
        tag = 1;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())  return false;
        front = (front+1)%MaxSize;
        tag = 0;
        return true;
    }
    
    int Front() {
        if(isEmpty())  return -1;
        return data[front];
    }
    
    int Rear() {
        if(isEmpty())  return -1;
        return data[(rear+MaxSize-1)%MaxSize];
    }
    
    bool isEmpty() {
        if(tag==0 && front==rear) 
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(tag==1 && front==rear) 
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
