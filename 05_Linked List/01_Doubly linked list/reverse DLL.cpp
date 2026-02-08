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

Node* convert_Arr_2_DLL (Node* & head, vector <int>& arr){
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

// brute force approch using stack
// Ye function Doubly Linked List ko reverse kar raha hai, but ek extra stack use karke sirf data reverse kar raha hai (nodes ke links nahi badal raha).
Node* reverse_DLL (Node* & head){
    Node* temp = head;
    stack <int> st;

    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        temp->data = st.top();  // value lo aur node me store karo
        st.pop();  // ab wo value stack se hata do
        temp = temp->next;
    }
    return head;
}

// optimal approch
Node* reverseDLL(Node* &head)
{   
    if(head == NULL || head->next == NULL){
        return head;
    }  

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr = curr->back;
    } 
    return prev->back;  // new head
}


int main(){
    vector <int> arr = {10, 20, 30, 40, 50};
    Node* head = new Node(arr[0]);

    convert_Arr_2_DLL (head, arr);
    print(head);

    reverse_DLL(head);
    print(head);

    head = reverseDLL(head);
    print(head);

    return 0;
}