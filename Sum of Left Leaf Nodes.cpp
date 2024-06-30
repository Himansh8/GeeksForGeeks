/*Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.*/



/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf nodes

void solve(Node* root,int &sum){
    if(root==NULL){
        return;
    }
    
    if(root->left){
        if(root->left->left==NULL && root->left->right==NULL){
            sum=sum+root->left->data;
        }
    }
    
    
    solve(root->left,sum);
    solve(root->right,sum);
}

int leftLeavesSum(Node *root)
{
    int sum=0;
    solve(root,sum);
    return sum;
}