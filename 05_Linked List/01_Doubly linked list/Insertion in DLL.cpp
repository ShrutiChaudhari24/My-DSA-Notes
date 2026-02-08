# include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

void print (Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node* convertArr2LL (Node* &head, vector <int>& arr){
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

Node* insert_Before_Head(Node* & head, int val){
    Node* newHead = new Node(val);
    newHead->next = head;
    newHead->back = nullptr;
    head->back = newHead;
    head = newHead;

    return head; 
}

Node* insert_Before_Tail(Node* & head, int val){
    // edge case
    if(head->next == NULL){
        return insert_Before_Head(head, val);
    }
    
    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val);
    newNode->next = tail;
    newNode->back = prev;
    prev->next = newNode;
    tail->back = newNode;

    return head;

}

Node* insert_before_k (Node* &head, int k, int val){
    // edge case
    if(k == 1){
        return insert_Before_Head(head, val);
    }

    Node* temp = head;
    int count = 1;
    while(temp != NULL){
        if(count == k){
            break;
        }
        temp = temp->next;
        count++;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->back = prev;
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insert_Before_Node(Node* node, int val){
    Node* prev = node->back;
    Node* newnode = new Node(val);
    newnode->next = node;
    newnode->back = prev;
    prev->next = newnode;
    node->back = newnode;
}

int main(){
    vector <int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    Node* head = new Node(arr[0]);

    print(head);

    convertArr2LL (head,arr);
    print(head);

    insert_Before_Head(head, 0);
    print(head);

    insert_Before_Tail(head, 95);
    print(head);

    insert_before_k (head, 3, 78);
    print(head);

    insert_Before_Node(head->next, 45);
    print(head);

    

 
    return 0;
}