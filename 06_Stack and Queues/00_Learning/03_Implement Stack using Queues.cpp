# include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue <int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
       int s = q.size();// number of elements already in queue
        q.push(x); // step 1: add new element at back

        for(int i = 1; i <q.size(); i++){   // step 2: rotate old elements
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();  // top element
        q.pop();  // remove it
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */