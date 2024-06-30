/*Given a Binary Tree of size N, your task is to complete the function rightLeafSum(),
which should return the sum of all the leaf nodes that are the right child of their parent of the given binary tree.*/

/*Structure of the node of the binary tree is as


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes
class Solution{
    private:
    
    void solve(Node* root, int &sum){
        if(root==NULL){
            return;
        }
        
        if(root->right){
            if(root->right->right==NULL && root->right->left==NULL){
                sum=sum+root->right->data;
            }
        }
        solve(root->right,sum);
        solve(root->left,sum);
        
    }
    
    public:
    int rightLeafSum(Node* root)
    {
         int sum=0;
         solve(root,sum);
         return sum;
    }
};