/*You are given an Undirected Graph having unit weight of the edges, 
find the shortest path from src to all the vertex and
if it is unreachable to reach any vertex, then return -1 for that vertex.*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>dist(N,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        vector<int>ans(N,-1);
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends