/*Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. */


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int postion(int ino[],int size,int target){
        for(int i=0;i<size;i++){
            if(ino[i] == target){
                ino[i] = -1;
                return i;
            }
        }
        return -1;
    }
    
    
    
    // void creation(map<int,int>hold,int in[],int n){
    //     for(int i=0;i<n;i++){
    //         hold[in[i]]=i;
    //     }
    // }
    
    Node* solve(int ino[],int preo[],int &preindex,int instart,int inlast,int n){
        
        if(preindex >= n || instart > inlast){
            return NULL;
        }
        
        int element=preo[preindex++];
        Node* root=new Node(element);
        
        int pos=postion(ino,n,element);
        // int pos=hold[element];
        
        root->left=solve(ino,preo,preindex,instart,pos-1,n);
        root->right=solve(ino,preo,preindex,pos+1,inlast,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preindex=0;
        // map<int,int>hold;
        // creation(hold,in,n);
        Node* ans=solve(in,pre,preindex,0,n-1,n);
        return ans;
    }
};