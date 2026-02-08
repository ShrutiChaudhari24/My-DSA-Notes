# include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack <int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {

        // step 1:= till we have elements in s1 push from s1 to s2
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        // step 2 := push new element
        s1.push(x);

        // step 3 := get everything back from s2 till we have elements in s2
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */