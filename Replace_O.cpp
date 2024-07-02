/*Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.*/



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int row,int col, vector<vector<int>>&visit, 
    vector<vector<char>> &mat,int drow[],int dcol[]){
        visit[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow<n && nrow>=0 &&ncol<m && ncol>=0 
            && !visit[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,visit,mat,drow,dcol);
            }
        }
    }
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>visit(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !visit[0][j]){
                dfs(0,j,visit,mat,drow,dcol);
            }
            
            if(mat[n-1][j]=='O' && !visit[n-1][j]){
                dfs(n-1,j,visit,mat,drow,dcol);
            }
        }
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !visit[i][0]){
                dfs(i,0,visit,mat,drow,dcol);
            }
            
            if(mat[i][m-1]=='O' && !visit[i][m-1]){
                dfs(i,m-1,visit,mat,drow,dcol);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends