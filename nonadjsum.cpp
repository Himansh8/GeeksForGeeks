/*Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.*/

//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
  
  pair<int,int> solve(Node* root){
      
      if(root==NULL){
          pair<int,int>p=make_pair(0,0);
          return p;
      }
      
      pair<int,int>leftpair=solve(root->left);
      pair<int,int>rightpair=solve(root->right);
      
      pair<int,int>p;
      p.first=root->data+leftpair.second+rightpair.second; 
      p.second=max(leftpair.first,leftpair.second)+max(rightpair.first,rightpair.second);
      
      return p;
  }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans;
        ans=solve(root);
        
        return max(ans.first,ans.second);
    }
};