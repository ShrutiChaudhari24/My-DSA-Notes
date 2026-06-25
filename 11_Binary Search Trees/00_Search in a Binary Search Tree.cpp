#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// to search a node in BST
Node* searchInBST (Node* root, int target){
    // keep on traversing till we get root pointer == Null and also root->data is not equal to the target we want to find

/*
    while(root != nullptr && root->data != target){
    if(target < root->data)
        root = root->left;
    else
        root = root->right;
}
return root;
*/

    while(root != nullptr && root->data != target){
        root = (target < root->data) ? (root->left) : (root->right);
    }
    return root;
}

// TC := 
// Best Case  : O(1)
// Average    : O(log n)
// Worst Case : O(n)

int main() {

//        8
//      /   \
//     5     12
//    / \   /  \
//   4   7 10   14
//      /       /
//     6      13

    Node* root = new Node(8);

    root->left = new Node(5);
    root->right = new Node(12);

    root->left->left = new Node(4);
    root->left->right = new Node(7);

    root->right->left = new Node(10);
    root->right->right = new Node(14);

    root->left->right->left = new Node(6);

    root->right->right->left = new Node(13);

    Node* result = searchInBST(root, 10);
    if(result != nullptr)
        cout << "Found: " << result->data;
    else
        cout << "Not Found";
    
    return 0;
}