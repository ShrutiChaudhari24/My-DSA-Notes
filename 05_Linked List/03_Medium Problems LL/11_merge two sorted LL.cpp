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

Node* convertArr2LL (Node* &head, vector <int>& arr){
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
}

Node* sortTwoLists(Node* first, Node* second){   
    // brute force approch 
    vector <int> arr;
        Node* temp1 = first; 
        Node* temp2 = second; 

        while(temp1 != NULL){
            arr.push_back(temp1->data);
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            arr.push_back(temp2->data);
            temp2 = temp2->next;
        }

        if (arr.empty()) return nullptr;  // only edge case needed

        sort(arr.begin(),arr.end());

        Node* sortedList = new Node (arr[0]);
        Node* mover = sortedList;
        for(int i = 1; i < arr.size(); i++){
            Node * temp = new Node (arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return sortedList;
}

Node* sortTwoLists1(Node* first, Node* second){   
     // optimal approch using concept of dummy node and not using any externa DS to store the list just making link changes to optimize the space complexity and using the property of sorted list TC := O(N + M) in worst case SC := O(1) 
        Node* t1 = first;
        Node* t2 = second;
        Node* dummyNode = new Node (-1);
        Node*  temp = dummyNode;

        // traverse in the both LL and the elements from which list is small put that in temp next
        while (t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        // if t2 is exhusted but t1 is still there
        if(t1 != NULL){
            temp->next = t1;
        }

        // if t1 is exhusted but t2 is still there
        if(t2 != NULL){
            temp->next = t2;
        }
        return dummyNode->next;
}

void print (Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }cout << endl;
}
 
int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head1 = new Node(arr[0]);
    vector <int> brr = {2,4,5,8};
    Node* head2 = new Node(brr[0]);

    convertArr2LL (head1, arr);
    convertArr2LL (head2, brr);
    print(head1);
    print(head2);

    // Node* head = sortTwoLists(head1, head2);
    // print(head);

    Node* head = sortTwoLists1(head1, head2);
    print(head);


    return 0;
}