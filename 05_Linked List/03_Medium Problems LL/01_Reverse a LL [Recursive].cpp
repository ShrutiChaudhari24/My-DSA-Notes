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

// TC := O(N) SC O(N)
Node* ReverseLL (Node* &head){
   if(head == NULL || head->next == NULL){
        return head;
   }

   Node* newHead = ReverseLL (head->next);

   Node* front = head->next;
   front->next = head;
   head->next = NULL;
   return newHead;
}

Node* convertArr2LL (Node* &head, vector <int>& arr){
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover  = temp;
    }
    return head;
}

void print (Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

int main(){
    vector <int> arr = {1, 2, 3, 4, 5};
    Node* head = new Node(arr[0]);

    convertArr2LL (head, arr);
    print(head);

    head = ReverseLL (head);
    print(head);
    return 0;
}
