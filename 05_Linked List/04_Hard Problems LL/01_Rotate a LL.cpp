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

Node* findNthNode(Node* temp, int k){
     int cnt = 1;
     while(temp != NULL){
          if(cnt == k) return temp;
          cnt++;
          temp = temp->next;
     }
     return temp;
}
Node *rotate(Node *head, int k) {
     // edge case := Node need of any rotation
     if(head == NULL || k ==0) return head;

     int len = 1;
     Node* tail = head;

     // finding the last length of LL and finding length of LL
     while(tail->next != NULL){
          len++;
          tail = tail->next;
     }

     // once we have found out the length we have to find how many rotations we have to do
     if(k % len == 0) return head; // no roattion require if k is exactly equal to len

     k = k % len;

     // attach the tail to the head
     tail->next = head;
     Node* newLastNode = findNthNode(head, len-k);

     head = newLastNode->next;
     newLastNode->next = NULL;
return head;
}

int main(){
    vector <int> arr = {1, 2, 3, 4, 5};
    Node* head = new Node(arr[0]);

    convertArr2LL (head, arr);
    print(head);

    head  = rotate(head, 2);
    print(head); 

    return 0;
}