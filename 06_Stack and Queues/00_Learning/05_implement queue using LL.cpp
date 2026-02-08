# include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedListQueue {
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = NULL;
        rear = NULL;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        if (rear == NULL) {   // queue empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int pop() {
        if (isEmpty()) return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL; // queue became empty
        return val;
    }
    
    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
};
