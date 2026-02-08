class Stack {
    int *arr;
    int topIndex;
    int cap;

public:
    Stack(int capacity) {
        cap = capacity;
        arr = new int[cap];
        topIndex = -1;
    }

    void push(int num) {
        if (topIndex == cap - 1) return;
        arr[++topIndex] = num;
    }

    int pop() {
        if (topIndex == -1) return -1;
        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) return -1;
        return arr[topIndex];
    }

    int isEmpty() {
        return topIndex == -1;
    }

    int isFull() {
        return topIndex == cap - 1;
    }
};
