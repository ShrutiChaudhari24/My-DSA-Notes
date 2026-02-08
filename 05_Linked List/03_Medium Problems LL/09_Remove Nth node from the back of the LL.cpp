# include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertArr2LL (Node* head, vector <int> & arr){
    Node* mover = head;
    
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
        temp = temp->next;
    }
    return head;
}

void print (Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node* Remove_Nth_Node_From_Last(Node* &head,int N){
    // approch 1 := brute force TC := O(length) + O(length-N) worst case O(2*N) SC:= O(1)
    // If list is empty, return NULL
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        Node* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If N equals the total number of nodes, delete the head
        if (cnt == N) {
            Node* newHead = head->next;
            // free memory
            delete head; 
            return newHead;
        }

        // Calculate the position from start to delete
        int res = cnt - N;
        temp = head;

        // Traverse to the node just before the one to delete
        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        // Delete the target node
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; // free memory

        return head;
}

Node* Remove_Nth_Node_From_Last2(Node* &head, int N) {

    if (head == NULL || N <= 0) return head;

    Node* fast = head;
    Node* slow = head;

    // Move fast N steps ahead
    for (int i = 0; i < N; i++) {
        if (fast == NULL) return head;  // N > length
        fast = fast->next;
    }

    // If fast is NULL → delete head
    if (fast == NULL) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete node
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;

    return head;
}

int main(){
    vector <int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = new Node(arr[0]);

    print(head);
    convertArr2LL(head,arr);
    print(head);
    Remove_Nth_Node_From_Last(head,2);
    print(head);
    Remove_Nth_Node_From_Last(head,8);
    print(head);
    head = Remove_Nth_Node_From_Last(head,8);
    print(head);

    Remove_Nth_Node_From_Last2(head,2);
    print(head);

    head = Remove_Nth_Node_From_Last2(head,6);
    print(head);
    return 0;
}