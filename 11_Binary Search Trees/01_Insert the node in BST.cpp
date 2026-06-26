# include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* InsertInBST(TreeNode* &root, int val){  // TC := O(Log N)

    if(root == NULL){
        root = new TreeNode(val);
        return root;
    }

    TreeNode *curr = root;

    while(true){

        if(curr->data <= val){

            if(curr->right != NULL){
                curr = curr->right;
            }
            else{
                curr->right = new TreeNode(val);
                break;
            }

        }
        else{

            if(curr->left != NULL){
                curr = curr->left;
            }
            else{
                curr->left = new TreeNode(val);
                break;
            }

        }

    }

    return root;
}
int main(){
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(5);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    root->left->right->left = new TreeNode(6);

    root->right->right->left = new TreeNode(13);

    InsertInBST(root, 5);

    return 0;
}