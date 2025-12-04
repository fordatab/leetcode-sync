class MyCircularQueue {
public:
    vector<int> queue;
    int headIdx = 0;
    int ct = 0;
    int capacity = 0;

    MyCircularQueue(int k) {
        capacity = k;
        queue = vector<int>(k); 
    }
    
    bool enQueue(int value) {
        if (ct == capacity) {
            return false;
        } 
        queue[(headIdx + ct) % capacity] = value;
        ct++;
        return true;
    }
    
    bool deQueue() {
        if (ct == 0) {
            return false;
        }
        headIdx = (headIdx + 1) % capacity;
        ct--;
        return true;
    }
    
    int Front() {
        if (ct == 0) {
            return -1;
        }
        return queue[headIdx];
    }
    
    int Rear() {
        if (ct == 0) {
            return - 1; 
        }
        int tailIdx = (headIdx + ct - 1) % capacity;
        return queue[tailIdx];
    }
    
    bool isEmpty() {
        return ct == 0;
    }
    
    bool isFull() {
        return ct == capacity;  
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