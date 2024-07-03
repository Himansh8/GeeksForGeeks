/*You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int row,int col, vector<vector<int>>&visit, 
        vector<vector<int>> &mat,int drow[],int dcol[]){
        visit[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 &&ncol<m && ncol>=0 
            && !visit[nrow][ncol] && mat[nrow][ncol]==1){
                dfs(nrow,ncol,visit,mat,drow,dcol);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !visit[0][j]){
                dfs(0,j,visit,grid,drow,dcol);
            }

            if(grid[n-1][j]==1 && !visit[n-1][j]){
                dfs(n-1,j,visit,grid,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !visit[i][0]){
                dfs(i,0,visit,grid,drow,dcol);
            }

            if(grid[i][m-1]==1 && !visit[i][m-1]){
                dfs(i,m-1,visit,grid,drow,dcol);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends