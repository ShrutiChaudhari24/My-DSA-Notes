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

vector<int> postorderTraversal(Node* root){
    vector <int> ans;

    if(root == nullptr) return ans;
    
    vector <int> left = postorderTraversal(root->left); 
    vector <int> right = postorderTraversal(root->right); 

    ans.insert(ans.begin(), left.begin(), left.end()); 
    ans.insert(ans.end(), right.begin(), right.end());  
    ans.push_back(root->data);

    return ans;
}

int main(){
    // creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->right = new Node(5);

    vector <int> ans = postorderTraversal(root);

    cout << "postorder Traversal: ";

    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}