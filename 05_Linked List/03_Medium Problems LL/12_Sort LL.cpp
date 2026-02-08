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
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

Node *sortLL(Node *head)
{
     // brute force approch overall TC := O(N + N logN + N) SC := O(N) because we are using external data structure array to store N LL elements
        //  put all the elements of LL into array
        // sort the array
        // reput the elements from array to LL (elements are sorted)
        Node* temp = head;
        vector <int> arr;

        // step 1 := put the elements into array TC := O(N)
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // step 2:= sort TC := O(N log N)
        sort(arr.begin(),arr.end());

        // step 3 := reput the array elements (that are sorted) from array to LL TC := O(N)
        temp = head; int i = 0;
        while(temp != NULL){
            temp->data = arr[i];
            i++;
            temp = temp->next;
        } 
        return head;
}

  // finding middle
    Node* findMiddle (Node* head){
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

     // merging two sorted list
    Node* merge2SortedList (Node* left, Node* right){
        Node* t1 = left;
        Node* t2 = right;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        // if t1 is exhusted
        if (t2 != NULL){
            temp->next = t2;
        }
         // if t2 is exhusted
        if (t1 != NULL){
            temp->next = t1;
        }
        return dummyNode->next;    
    }


Node *sortLL1(Node *head)
{
    //  optimal approch without using any external data structure like array etc sloving in SC := O(1) this means we have to do something in linklist itself 
    // we are using any of the sorting algorithm like merge sort, quick sort etc 
    // quick sort is little bit difficult to implement so we will be using merge sort algo
    // but before implement merge sort we have to first learn how to merge two sorted linked list so go to 11_merge two sorted LL.cpp
        // edge case 
        if(head == NULL || head->next == NULL) return head;

        // break in middle
        Node* middle = findMiddle (head);
        Node* left = head;
        Node* right = middle->next;
        middle->next = NULL;
        
        left = sortLL1(left);
        right = sortLL1(right);
        

        return merge2SortedList (left, right);
    }

int main(){
    vector <int> arr = {12, 34, 21, 24, 67, 45, 90,2004};
    Node* head = new Node(arr[0]);

    print (head);
    convertArr2LL (head,arr);
    print(head);

    // sortLL(head);
    // print(head);

    sortLL1(head);
    print(head);

    return 0;
}
