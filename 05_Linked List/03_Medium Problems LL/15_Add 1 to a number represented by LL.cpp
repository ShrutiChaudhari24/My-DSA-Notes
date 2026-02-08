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

Node* reverse (Node* &head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* Add1_to_LL (Node* head){
    //brute force approch by reversing traversing and adding again reversing TC := O(3N) SC := O(1)
    // step 1 := reverse
    head = reverse(head);
    
    // step 2 := treverse 
    Node* temp = head;
    int carry = 1;

    while(temp != NULL){
        temp->data = temp->data + carry;

        // if temp ka data is under 10 wali value
        if(temp->data < 10){
            carry = 0; // set carry to 0 and break
            break;
        }
        else{  // ager temp ka data greater than or equal to 10 hai tho 
            temp->data = 0;  // data ko 0 sae replace kar doo 
            carry = 1; // aur carry ko 1 kar doo
        }
        temp = temp->next;
    }

    // if still carry is 1 ie there should be a extra node 
    if(carry == 1){
        Node* newHead = new Node(1); // ek new node create karo
        head = reverse(head); // again reverse karlo head ko so that its original state preserve
        newHead->next = head;
        return newHead;
    }

    // ager carry 0 hogi tho straight a way return head after reversal
    reverse(head);
    return head;
}

// helper function to get the carry this is the recursive function
int helper(Node* temp){
    // base case := whenever we reach null
    if(temp == NULL){
        return 1;
    }
    int carry = helper(temp->next);  // recursive call

    // this is entire backtracking we will do while comming back we will perform job
    temp->data = temp->data + carry;
    if (temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    // recursive solution TC := O(N) SC:= O(N)
    
    // this is the final carry 
    int carry = helper (head);

    // if carry is equal to 1 then we have to create new node
    if(carry == 1){
        Node* newhead = new Node(1);
        newhead->next = head;
        return newhead;
    }
    return head;
}

int main(){
    // vector <int> arr = {1,5,9};
    vector <int> arr = {9,9,9,9};
    Node* head = new Node(arr[0]);

    print(head);
    convertArr2LL(head,arr);
    print(head);

    head = Add1_to_LL (head);
    print(head);

    addOne(head);
    print(head);


    return 0;
}