/*Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a unique binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Note :- The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.*/

//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int postion(int in[],int target,int n){
    for(int i=0;i<n;i++){
        if(in[i]==target){
            in[i]=-1;
            return i;
        }
    }
    return -1;
}

Node*  solve(int in[],int post[],int &index,int instart,int inlast,int n){
    
    if(index < 0 || instart > inlast){
         return NULL;
    }
    
    int element=post[index--];
    Node* root=new Node(element);
    
    int pos=postion(in,element,n);
    
    root->right=solve(in,post,index,pos+1,inlast,n);
    root->left=solve(in,post,index,instart,pos-1,n);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {

    int postindex=n-1;
    Node* ans=solve(in,post,postindex,0,n-1,n);
    return ans;
    
}


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends