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

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node* convertArr2LL (vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i  = 1; i <arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// 1) Insert at head
Node* insert_At_Head(Node* &head, int element){
    Node * temp = new Node(element);
    temp->next = head;
    head = temp;
    return temp;
}

// 2) Insert at tail
Node* insert_At_Tail(Node* &head, int element){
   
    if(head == NULL){
        return new Node(element);
    } 

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(element);
    temp->next = newNode; 
    return head;
}

// 3) Insert at any k position
Node* insert_at_K_position(Node* & head, int k, int element){
    
    // edge case:- 1) LL is empty 
    if(head == NULL){
        // and k == 1 so we have to insert at 1st position
        if(k==1){
            return new Node (element);
        }
        else{
            // this case is not possible arey bhai ager LL mae kuch hai hi nahi tho ya tho tum element ko 1st position pae insert karoge nahi tho kaya hi karoge
            return NULL;
        } 
    }

    // edge case:- 2) we have to insert the element at head
    if(k == 1){
        Node* temp = new Node(element);
        temp->next = head;
        head = temp;
        return head;
    }

    // k kuch bhi ho sakta hai except 1
    int count = 1;
    Node* temp = head;
    while(temp != NULL){
        if(count == k-1){
            Node* x = new Node(element);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
        count++;
    }
return head;
} 

// 4) Insert element (specific element) before the value n 
Node* insertBeforeValue (Node* &head, int element, int val){
    // edge case 1:- if the LL is empty then there is no value present jiskae phele hum kuch insert kar paye
    if(head == NULL){
        return NULL;
    }

    // edge case 2:- head kae phele hi insert karna ho
    if(head->data == val){
        // return new Node(element);  //one liner or we can also do like this
        Node* temp  = new Node(element);
        temp->next = head;
        head = temp;
        return head; 
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(element);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector <int> arr = {100, 234, 35, 68, 675, 240, 109};

    // Create linked list
    Node* head = convertArr2LL(arr);
    print(head);

    insert_At_Head(head,88);
    print(head);

    insert_At_Tail(head, 50);
    print(head);

    insert_at_K_position(head, 1, 2006);
    print(head);

    insert_at_K_position(head, 3, 200);
    print(head);

    insert_at_K_position(head, 12, 21221);
    print(head);

    insert_at_K_position(head, 14, 2332); //this will not happen
    print(head);

    insertBeforeValue (head, 2924, 200);
    print(head);

    insertBeforeValue (head, 5667, 2006);
    print(head);


    return 0;
}