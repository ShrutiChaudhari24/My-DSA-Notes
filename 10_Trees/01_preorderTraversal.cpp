# include <bits/stdc++.h>
using namespace std;

// hum yaha struct ki jaghe pae class bhi use kar sakte thae but using struct is also ok because A node is often just a data container: It doesn't usually hide data or enforce rules. So programmers commonly use struct for simple data objects. But when you want encapsulation (data hiding) and member functions, people generally prefer class 
// | Feature             | struct   | class     |
// | ------------------- | -------- | --------- |
// | Default access      | `public` | `private` |
// | Default inheritance | `public` | `private` |

// Using a struct is convenient since everything is public by default.

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the values
    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> preorderTraversal(Node* root){
    vector <int> ans;

    if(root == nullptr) return ans;
    
    // as we know that preorder traversal is root -> left -> right 
    ans.push_back(root->data); // so first insert the root value

    vector <int> left = preorderTraversal(root->left); // recursively call the preorderTraversal function till we reach to the nullptr at left so that the values are returned 
    vector <int> right = preorderTraversal(root->right); // same as left for right

    // now we have the left and right vectors so insert them into answer
    ans.insert(ans.end(), left.begin(), left.end()); // means insert into ans at the end what we are going to insert is left vector from begin to end
    ans.insert(ans.end(), right.begin(), right.end());  // similarly then insert the right vector

    return ans;
}

int main(){
    // creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->right = new Node(5);

    vector <int> ans = preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}