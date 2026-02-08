# include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this ->next = nullptr;
    }
};

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " "; 
        temp = temp -> next;
    }cout << endl;
}

// 1) deletion of head of the linked list
Node* delete_Head_of_LL(Node* &head){
    // edge cae sub jaghe likhna ager linked list empty hai
    if(head == NULL){
        return head;
    }

    Node* temp = head;
    head = head->next;
    delete(temp); 
    // free(temp);

    return head;
}

//2) deletion of tail of the linked list
Node* delete_Tail_of_LL(Node* &head){
    Node* temp = head;

    // edge case if the linked list is empty or LL contains only one element what we have to do in both cases we have to return NUll beause if the list is empty the what we will do nothing and if there is only one element in the list the we have to delete that one element and the ret remaing is null only
    if(head == NULL || head->next == NULL) return nullptr;

    // apart from the above cases the list contain 2 or more elements ie. nodes
    while(temp->next->next != nullptr){ //ager temp kae next ka next null nahi hai tho temp ko aage badaho
        temp = temp ->next;
    }
    delete(temp->next); // jab temp->next ka next null hoga tho temp kae next ko delete kardo
    temp->next = nullptr; //aur jo temp hai uss kae next ko null ko point karwa doo 

    return head;
}

//3) deletion at any position k of the LL
Node* delete_at_any_position_k(Node* &head, int k){
    // edge case:= 1 if LL is empty
    if(head == NULL) return head;
    
    // edge case:=2 if k==1 ie we have to delete head itself
    if(k == 1){
        Node* temp = head;
        head = temp ->next;
        delete(temp);
        return head;
    }

    // if k is any position 
    int count = 1;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(count == k){
            prev->next = temp->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    // If k > list length, nothing happens (no deletion)
    return head;
} 

//4) delete any specific element given to us 
Node* delete_element (Node* &head, int element){
    if(head == NULL) return head;

    if(head->data == element){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == element){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


Node* convertArr2LL (Node* head, vector<int>& arr){
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}



int main(){
    vector <int> arr = {1, 4, 21, 22, 35, 29};

    Node* head = new Node(arr[0]);

    convertArr2LL (head,arr);

    print(head); //before deletion of head
    delete_Head_of_LL(head);
    print(head); // after deletion of head

    print(head);//before deletion of tail
    delete_Tail_of_LL(head);
    print(head);//after deletion of tail

    print(head);//before deletion of kth position element
    delete_at_any_position_k(head, 7);//invalid position delete nothing
    delete_at_any_position_k(head, 2);//delete the node at 2nd position;
    print(head);//after deletion of kth position element

    delete_element (head,22);
    print(head);

    return 0;
}