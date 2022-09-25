class MyCircularQueue {
public:
    int* data;
    int head=-1;
    int tail=-1;
    int size=0;
    
    MyCircularQueue(int k) {
        size = k;
        data = new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty())
            head = 0;
        
        tail = (tail+1)%size;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if(!isEmpty())
            return data[head];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return data[tail];
        return -1;
    }
    
    bool isEmpty() {
        if(head == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((tail + 1)% size == head)
            return true;
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