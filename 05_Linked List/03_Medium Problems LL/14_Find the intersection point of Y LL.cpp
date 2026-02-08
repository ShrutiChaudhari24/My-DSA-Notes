#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
 
Node *getIntersectionNode(Node *headA, Node *headB) {
        // brute force approch TC := O(N1 * LogN1) + O(N2 * log2) or TC := O(N1 * 1) + O(N2 * 1) depend upon map
        // SC := O(N1) or O(N2) depends which LL we are storing
        Node* temp = headA;
        map <Node*,int> mpp;

        // first store the list 1 into map TC := O(N1 * logN1) or if we use unordered map TC := O(N1 * 1) for storing the node in map
        while(temp != NULL){
            mpp[temp] = 1;
            temp = temp->next;
        }

        //now traversing the list 2 to identify the visited node once we got the visited node we will straight a way return first intersection node
        // now placing temp at list 2 
        // TC := O(N2 *  log N2) if ordered map if unordered TC := O(N2 * 1) becaude of find operation
        temp = headB;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            temp = temp->next;
        }
        return NULL; // we did not get the intersection node
}

// approch 2 TC := O(n1 + n2) SC:= O(1)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* t1 = firstHead;
    Node* t2 = secondHead;
    int n1 = 0, n2 = 0;

    // step 1 := figure out the length
    while(t1 != NULL){
        n1++;
        t1 = t1->next;
    }
     while(t2 != NULL){
        n2++;
        t2 = t2->next;
    }

    // Reset pointers
    t1 = firstHead;
    t2 = secondHead;
    
    // step 2 := longer LL must travell the extra distance
    if (n1 < n2){
        int d = n2-n1;
        while(d != 0){
            t2 = t2->next;
            d--;
        }
    }else{
        int d = n1-n2;
        while( d != 0){
            t1 = t1->next;
            d--;
        }
    }

    // step 3 := comparision
    while(t1 != NULL && t2 != NULL){
        if (t1 == t2){
            return t1; // or we can return t2 
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return NULL;
}

Node* findIntersection1(Node *firstHead, Node *secondHead)
{   
    // approch 3 := optimal approch  TC := O(N) SC := O(1)
    if (firstHead == NULL || secondHead == NULL) return NULL;

    Node* t1 = firstHead;
    Node* t2 = secondHead;

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

        // while traversing if they collide
        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = secondHead;
        
        if(t2 == NULL) t2 = firstHead;
    }
    return t1;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Common part (intersection)
    Node* common = new Node(8);
    common->next = new Node(10);

    // List A: 1 -> 2 -> 3 -> 8 -> 10
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common;

    // List B: 5 -> 6 -> 8 -> 10
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = common;

    cout << "List A: ";
    print(headA);

    cout << "List B: ";
    print(headB);

    Node* ans = getIntersectionNode(headA, headB);
    if (ans)
        cout << "Intersection Node: " << ans->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
