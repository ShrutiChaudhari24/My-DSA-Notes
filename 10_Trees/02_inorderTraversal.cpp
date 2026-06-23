# include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> inorderTraversal(Node* root){
    vector <int> ans;

    if(root == nullptr) return ans;
    
    ans.push_back(root->data);

    vector <int> left = inorderTraversal(root->left); 
    vector <int> right = inorderTraversal(root->right); 

    ans.insert(ans.begin(), left.begin(), left.end()); 
    ans.insert(ans.end(), right.begin(), right.end());  

    return ans;
}

int main(){
    // creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->right = new Node(5);

    vector <int> ans = inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}