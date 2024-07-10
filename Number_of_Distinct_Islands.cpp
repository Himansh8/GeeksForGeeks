//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int row,int col, vector<vector<int>>& grid,vector<vector<int>>& visit,int row0,int col0,vector<pair<int,int>>& hold){
        
        visit[row][col]=1;
        hold.push_back({row0-row,col0-col});
        // hold.push_back({row - row0, col - col0});
        int n=grid.size();
        int m=grid[0].size();
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && visit[nrow][ncol]==0){
                dfs(nrow,ncol,grid,visit,row0,col0,hold);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visit[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>hold;
                    dfs(i,j,grid,visit,i,j,hold);
                    st.insert(hold);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends