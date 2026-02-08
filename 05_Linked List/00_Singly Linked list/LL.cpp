#include <bits/stdc++.h>
using namespace std;

// struct 
class Node {
    public:
    int data;
    Node* next;
    
    public: //Do you need public: before constructor?
            //➡ No, if you already wrote public: above and didn’t switch to private: in between.
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:  // we can also write like this
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector <int> arr = {2, 5, 8, 7};
    // techinally use this
    Node* y = new Node (arr[0], nullptr);  // y is pointer to this memory location we can give any name hum node name bhi dae sakte thae ess ko 
    cout << y << endl; // o/p := 0x11b1a70 pointer to the memory location 
    cout << y->data << endl;  // jab pointer hota hai y tho -> ye use karte hai  
    cout <<y->next << endl;

    // ager new hata diya tho error aayega
    // Node y = Node (arr[0], nullptr);  // y is pointer to this memory location we can give any name hum node name bhi dae sakte thae ess ko 
    // cout << y.data << endl; // jab y simply ek variable hai tho . sae access karte hai
    // cout <<y.next << endl;

    Node* node = new Node(arr[0]);



    return 0;
}