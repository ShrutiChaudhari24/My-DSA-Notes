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
Node *detectCycle(Node *head) {
        // brute force approch using hashing TC:= O(N * 2LogN) SC:= O(1)
        
        // map <ListNode*, int> mpp;
        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){
        //         return temp;
        //     }

        //     mpp[temp] = 1;
        //     temp = temp->next; 
        // }
        // return NULL;

    // optimal approch using tortoise and hare algo (fast and slow pointer) TC:= O(N) SC:=O(1)
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // step 1 detect is there is a loop
            if(slow == fast){
                // step to detect 1st node
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        // if loop nahi hoga ie slow != fast 
        return NULL;
    }