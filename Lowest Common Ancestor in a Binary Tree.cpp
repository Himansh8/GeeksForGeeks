/*Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.*/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL){
           return NULL;
       }
       
      if(root->data==n1 || root->data==n2){
          return root;
      }
       
       Node* leftval=lca(root->left,n1,n2);
       Node* rightval=lca(root->right,n1,n2);
       
       if(leftval!=NULL && rightval!=NULL){
           return root;
       }
       if(leftval==NULL && rightval!=NULL){
           return rightval;
       }else if(leftval!=NULL && rightval==NULL){
           return leftval;
       }else{
           return NULL;
       }
    }
};