#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void preorder(Node* node){
    if(node == nullptr) return;

    cout << node->data << " ";
    preorder(node->left);     
    preorder(node->right);    
}

void inorder(Node* node){
    if(node == nullptr) return;

    inorder(node->left);      
    cout << node->data << " ";
    inorder(node->right);    
}

void postorder(Node* node){
    if(node == nullptr) return;

    postorder(node->left);    
    postorder(node->right);   
    cout << node->data << " ";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}