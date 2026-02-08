# include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = nullptr; 
    }
};

// brute force approch := TC := O(2N) SC:= O(N) using stack
// Node* ReverseLL (Node* &head){
//     Node* temp = head;
//     stack <int> st;
    
//     while(temp != NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     temp = head;

//     while(temp != NULL){
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }

//     return head;
// }


Node* ReverseLL (Node* &head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front ;

    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

