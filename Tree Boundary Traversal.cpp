/*Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. */

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    private:
    void left_traversal(Node* root,vector<int> &ans){
        if(root == NULL || (root->left ==NULL && root->right ==NULL)){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            left_traversal(root->left,ans);
        }else{
            left_traversal(root->right,ans);
        }
    }
    
    void right_traversal(Node* root,vector<int> &ans){
        if(root == NULL || (root->left ==NULL && root->right ==NULL)){
            return;
        }
        if(root->right){
            right_traversal(root->right,ans);
        }else{
            right_traversal(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    void leaf_traversal(Node* root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        leaf_traversal(root->left,ans);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        leaf_traversal(root->right,ans);
    }

public:
    vector <int> boundary(Node *root)
    {
    vector<int>ans;
    if(root){
        ans.push_back(root->data);
    }
    left_traversal(root->left,ans);
    leaf_traversal(root->left,ans);
    leaf_traversal(root->right,ans);
    right_traversal(root->right,ans);
    return ans;
    }
};