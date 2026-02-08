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

Node* reverse_Second_Half(Node* newHead){
    Node* temp = newHead;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}


// approch 1 := using stack DS TC = O(2N) SC = O(N)  
bool check_Is_palindrome (Node* &head){
    Node* temp = head;
    stack <int> st;

    // inserting into stack 
    // as stack is LIFO we get the LL elements in reverse order so we can compare first element with last second with second last and so on
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    // now again putting temp to head so that we can compare it with stack top element
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()){
            return false;
        }

        st.pop();
        temp = temp->next;
    }

    return true;
}

// approch 2 := optimal approch TC = O(2N) SC = O(1)  
bool check_Is_palindrome2 (Node* &head){
    // if the LL contain one node or it is empty it is palindrome so return true
    if(head == NULL || head->next == NULL) return true;

    // step 1 find middle
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2 reverese
    Node* newHead = reverse_Second_Half(slow->next);

    // step 3 comparision

    Node* first = head;
    Node* second = newHead;

    while(second != NULL){
        if(first->data != second->data){
            reverse_Second_Half(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }
    reverse_Second_Half(newHead);
    return true;
}

int main(){
    vector <int> arr = {1, 2, 3, 3, 2, 1};
    Node* head = convertArr2LL (arr);

    print(head);

    bool isPalindrome = check_Is_palindrome(head);
    cout << isPalindrome;
    cout << endl;
    bool isPalindrome2 = check_Is_palindrome2(head);
    cout << isPalindrome2;


    return 0;
}