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

Node* convertArr2LL (Node* head, vector <int>& arr){
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node* deleteMiddle1(Node* head){
        // approch 1 := TC := O(N + N/2) SC := O(1)

        // if the list is empty or it contains only one node in such cases we have to just return head
        if(head == NULL || head->next == NULL) return NULL;

        Node* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        } 

        int res = count/2;  //this is th position of the middle-1 node
        temp = head; // again point temp to front(head)
        
        while(temp != NULL){
            res--;

            if(res == 0){
                Node* middleNode = temp->next;
                temp->next = temp->next->next;
                delete middleNode;
                break;
            }

            temp = temp->next;
        }
        return head;
    }


// optimal approch
Node* deleteMiddle(Node* head){

    // using tortoise and hare algorithm TC := O(N/2) SC := O(1)

    // edge case if the linklist is empty or it contain only one node in both the cases we have to return the null
    if(head == NULL || head->next == NULL) return NULL;

    Node* fast = head;
    Node* slow = head;

    fast = fast->next->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // we are sure that slow is pointing to the node just previous to the middle node
    Node* middleNode = slow->next;
    slow->next = slow->next->next;
    delete middleNode;

    return head;
}

int main(){
    vector <int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = new Node(arr[0]);

    print (head);
    convertArr2LL (head,arr);
    print(head);


    deleteMiddle1(head);
    print(head);

    deleteMiddle(head);
    print(head);
    
    return 0;
}
