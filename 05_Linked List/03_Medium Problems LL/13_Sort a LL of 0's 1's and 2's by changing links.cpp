# include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
// convert array to linked list
Node* convertArr2LL (Node* &head ,vector <int> &arr){
    
    Node* mover = head; 
    
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;  //phele mover temp ko point karega
        mover = temp;// phir mover khud temp ban jayega 

    }
    return head;
}

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " "; 
        temp = temp -> next;
    }cout << endl;
}

Node* sortList(Node *head){
    // brute force approch TC := O(2N) SC := O(1)
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;

    // step 1 := traverse and count no of 0s,1s and 2s TC := O(N) 
    while(temp != NULL){
        if(temp->data == 0){
            cnt0++;
        }
        else if(temp->data == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp = temp->next;
    }

    // step 2 := again traverse and do data replacement TC := O(N)
    temp = head;
    while(temp != NULL){
        if (cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

Node* sortList1(Node *head){
    // optimal approch using the concept of dummy nodes one pass solution TC := O(N) SC := O(1) 
    
    //edge case
    if(head == NULL || head->next == NULL) return head;

    // assigning the dummy nodes 
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    // assign pointers for traversal
    Node* temp = head;
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    // this while loop will make suru that the link changes will happen and we will get three LL for 0, 1 and 2
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // now we have 0, 1 and 2 wali LL
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);  // if one is not present it will point to 2 wali LL
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    // delete all the dummy nodes to free the space
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead; 
}

int main(){
    vector <int> arr = {0,1,2,1,2,0,1,0,0,2,1,2,2,2,1,0};
    Node* head = new Node(arr[0]);

    print (head);
    convertArr2LL (head,arr);
    print(head);

    // sortList(head);
    // print(head);

    sortList1(head);
    print(head);

    return 0;
}