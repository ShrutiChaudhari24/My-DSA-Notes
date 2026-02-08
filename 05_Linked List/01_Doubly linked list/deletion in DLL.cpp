# include <bits/stdc++.h>
using namespace std;

class Node {
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

// delete head of the linked list
Node* deleteHead (Node* &head){
    // edge case 1:= DLL is empty // edge case 2:= DLL contains only 1 element and we have to delete that 1 element
    // in both the cases we return null
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    
    return head;
}

// delete tail of the linked list
Node* deleteTail (Node* &head){
    // edge case 1:- DLL is empty // edge case 2:= DLL contains only 1 element and we have to delete that 1 element 
    // in both the cases we return null
    if(head  == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    } 

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

// delete the kth element of DLL
Node* delete_Kth_element (Node* &head, int k){

    //edge case := 1) if linked list is empty
    if(head == NULL){
        return NULL;
    }

    Node* temp = head;
    int count = 1; // we are at 1st node

    while(temp != NULL){   // to reach to the kth position
        if(count == k){   
            break;
        }
        temp = temp->next;
        count++;
    }

    // once we have reach to the kth position standing to the kth position we want to take prev and front of that kth node as we have to delete that kth node
    Node* prev = temp->back;
    Node* front = temp->next;

    // edge case := 2)if the DLL has only one node
    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }

    // edge case := 3) if prev is NULL means we have to delete the node that node is head node
    if(prev == NULL){
        return deleteHead (head);   // so calling the delete head function
    }

    // edge case := 4) if front is NULL means we have to delete the node that node is tail node
    if(front == NULL){
        return deleteTail (head);  // calling delete tail function
    }

    // now if all the above edge cases are not satisfied that means the kth node is somewhere in between
    // so to delete that
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    delete temp;

    return head;
}

// if we have to delete the particular node in LL, constraint is the node given for deletion is not a head node
void deleteNode (Node* temp){
    
    Node* prev = temp->back;
    Node* front = temp->next;

    // edge case
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return ;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node* convertArr2DLL(Node* &head, vector<int>& arr){
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

int main(){
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = new Node(arr[0]);

    print(head);
    convertArr2DLL(head,arr);
    print(head);

    deleteHead (head);
    print(head);

    deleteTail (head);
    print(head);

    delete_Kth_element (head, 1);
    print(head);

    delete_Kth_element (head, 7);
    print(head);

    delete_Kth_element (head, 5);
    print(head);

    deleteNode (head->next);
    print(head);

    deleteNode (head->next->next);
    print(head);

    // deleteNode (head);   // if we say delete head the we have to put more and more conditions that's why that constarint
    // print(head);


    return 0;
}