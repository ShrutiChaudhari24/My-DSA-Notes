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

// to find length of the linked list
int lengthOfLL (Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp ->next;
        count++;
    }
return count;
}

// search an element in an linked list
int checkIfPresent(Node* head, int target){
    Node* temp = head;
    while(temp != nullptr){
        if(temp ->data == target){
            return 1;
        }
        else{
            temp = temp ->next;
        }
    }
return 0;
}

int main(){
    vector <int> arr = {2, 1, 3, 8};

    Node* head = convertArr2LL(arr);
    // cout << head->data;

    // traversal in LL
    Node* temp = head;
    while(temp != nullptr){ // or while(temp){}
        cout << temp->data << " ";
        temp = temp ->next; // updation
    }cout << endl;

    int length = lengthOfLL(head);
    cout << length << endl;

    int isPresent = checkIfPresent(head, 2);
    cout << isPresent << endl;


    return 0;
}