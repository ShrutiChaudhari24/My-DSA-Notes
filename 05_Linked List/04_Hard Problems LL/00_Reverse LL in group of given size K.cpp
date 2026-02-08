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

Node* reverseLL (Node* head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front;

    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* get_Kth_Node (Node* temp, int k){
    k = k-1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp != NULL){
        Node* kthNode = get_Kth_Node(temp,k);
        if(kthNode == NULL){
            if(prevLast) prevLast->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
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

    head = kReverse(head,3);
    print(head);
    return 0;
}
