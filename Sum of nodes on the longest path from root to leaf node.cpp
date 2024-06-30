/*Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.*/

//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:

    void solve(Node* root,int len,int &maxlen,int sum,int &maxsum){
        if(root==NULL){
            if(maxlen<len){
                maxlen=len;
                maxsum=sum;
            }
            
            if(maxlen==len){
                maxsum=max(maxsum,sum);
            }
            return;
        }
        
        sum=sum+root->data;
        
        solve(root->left,len+1,maxlen,sum,maxsum);
        solve(root->right,len+1,maxlen,sum,maxsum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len=0;
        int maxlen=0;
        int sum=0;
        int maxsum=INT_MIN;
        
        solve(root,len,maxlen,sum,maxsum);
        return maxsum;
    }
};