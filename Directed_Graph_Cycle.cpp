/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool checkdfs(int node,vector<int> adj[],int visit[],int pathvisit[]){
        visit[node]=1;
        pathvisit[node]=1;
        for(auto it:adj[node]){
            if(visit[it]==0){
                if(checkdfs(it,adj,visit,pathvisit)==true){
                    return true;
                }
            }else if(pathvisit[it]==1){
                return true;
            }
        }
        
        
        pathvisit[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int visit[V]={0};
        int pathvisit[V]={0};
        
        for(int i=0;i<V;i++){
            if(visit[i]==0){
                if(checkdfs(i,adj,visit,pathvisit)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends