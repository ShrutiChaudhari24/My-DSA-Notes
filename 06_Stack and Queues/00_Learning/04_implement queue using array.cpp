class ArrayQueue {
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    ArrayQueue() {
        capacity = 1000;   // fixed size
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    
    void push(int x) {
        rear++;
        arr[rear] = x;
    }
    
    int pop() {
        if (isEmpty()) return -1;
        return arr[front++];
    }
    
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    bool isEmpty() {
        return front > rear;
    }
};
