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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if (temp1) sum = sum + temp1->data;
        if (temp2) sum = sum + temp2->data;
        Node* newNode = new Node(sum %10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;

        if(carry){
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
    }
    return dummyHead->next;
}

int main(){
    vector <int> arr = {2,4,6};
    vector <int> brr = {3,8,7};
    Node* head1 = new Node(arr[0]);
    Node* head2 = new Node(brr[0]);

    print(head1);
    convertArr2LL(head1,arr);
    print(head1);

    print(head2);
    convertArr2LL(head2,brr);
    print(head2);

    Node* head = addTwoNumbers(head1,head2);
    print(head);

    return 0;
}