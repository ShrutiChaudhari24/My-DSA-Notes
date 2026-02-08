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
Node* convertArr2LL (vector <int> &arr){
    Node* head = new Node(arr[0]);
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

Node* segragateList_Odd_even (Node* &head){
    // approch 1 := Total TC := O(2N) SC := O(N) because we are using external data structure to store the list elements
    
    // edge case if there is only one node in LL or if the list is empty
    if(head == NULL || head->next == NULL){
        return head;
    }
    vector <int> arr;

    // step 1 := put odd nodes in the list TC := O(N/2)
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp =  temp->next->next;
    }
    if(temp != NULL) arr.push_back(temp->data); // if any node left

    // step 2 := put even nodes in the list TC := O(N/2)
    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp =  temp->next->next;
    }
    if(temp != NULL) arr.push_back(temp->data); // if any node left

    // step 3 := reput the elements into list
    temp = head;
    for(int i = 0; i < arr.size(); i++){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

Node *oddEvenLinkedList(Node *head) {
    // approch 2 := optimal approch using odd and even pointer TC := O(N) SC := O(1)

    // edge case
    if(head == NULL && head->next == NULL){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    // last odd node must point to the even first node
    odd->next = evenHead;
    return head;
}

int main(){
    vector <int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL (arr);

    print(head);

    // 1st approch
    segragateList_Odd_even (head);
    print(head);

    // 2nd approch
    oddEvenLinkedList(head);
    print(head);
    
    return 0;
}