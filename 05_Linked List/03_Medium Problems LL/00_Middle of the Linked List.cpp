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

Node* middleNode (Node* &head){
    // approch 1 :- TC := O(N + N/2) SC := O(1)
        // ListNode* temp = head;
        // int count = 0;

        // while(temp != NULL){
        //     count++;
        //     temp = temp->next;
        // }
        // int middleNode = (count/2) + 1;
        // temp = head;
        // while(temp != NULL){
        //     middleNode = middleNode-1;
        //     if(middleNode == 0){
        //         break;
        //     }
        //     temp = temp->next;
        // } 
        // return temp;


        // approch 2 := using slow and fast pointer TC:= O(N/2) SC:= O(1) 
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

int main(){

    return 0;
}