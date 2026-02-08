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

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

// convert array to linked list
Node* convertArr2LL (Node* &head, vector <int> &arr){
    Node* mover = head; 
    
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;  //phele mover temp ko point karega
        mover = temp;// phir mover khud temp ban jayega 

    }
    return head;
}

int length_of_loop (Node* head){
    // approch 1:= hashing TC := O(N * 2 * Log N) or TC:= O(N * 2 * 1) depends upon hash function  SC := O(N)  
    // map <Node*, int> mpp;
    // Node* temp = head;
    // int timer = 1;

    // while(temp != NULL){
    //     if(mpp.find(temp) != mpp.end()){
    //         int value = mpp[temp];
    //         return (timer-value);
    //     }
    //     mpp[temp] = timer;
    //     timer++;
    //     temp = temp->next;
    // }
    // return 0;

    // approch 2 := using tortoise and hare algorithm slow and fast pointer
    // TC := O(N) SC := O(1)
    Node* slow = head;
    Node* fast = head;
    

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            int count = 1;
            fast = fast->next;
            while(slow != fast){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
return 0;
}

        int main() {
        vector<int> arr = {24, 5, 2004, 19, 5, 8, 11, 4, 1};
        Node* head = new Node(arr[0]);
        convertArr2LL(head, arr);
        print(head);

        // Create a loop for testing
        Node* temp = head;
        Node* loopNode = nullptr;
        int pos = 3;

        int i = 1;
        while (temp->next != nullptr) {
            if (i == pos) loopNode = temp;
            temp = temp->next;
            i++;
        }
        temp->next = loopNode;

        int length = length_of_loop(head);
        cout << length << endl;

        return 0;
    }

