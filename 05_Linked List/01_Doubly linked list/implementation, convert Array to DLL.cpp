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

void print (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* convertArr2DLL (Node* &head, vector <int>& arr){
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);  //yaha humnae directly hi next ko null aur prev ko back pointer dae diya
        prev->next = temp;
        temp->back = prev;
        prev = temp;
        // temp = temp->next;  // Bad practice: temp->next abhi nullptr hai aur next iteration me temp use hi nahi hota, isliye ye line unnecessary hai
        
    }
    return head;
}

int main(){
    vector <int> arr ={24, 5, 2004, 19, 5, 8, 11, 4, 1};
    Node* head = new Node(arr[0]);

    print(head);
    cout << endl;
    convertArr2DLL(head,arr);
    print(head);



    return 0;
}