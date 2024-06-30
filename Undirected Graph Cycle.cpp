/*Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.*/

class Solution {
  private:
  
    bool detect(int target,int vis[],vector<int> adj[]){
        vis[target]=1;
        
        queue<pair<int ,int>>q;
        q.push({target,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }else if(par!=it){
                    return true;
                }
            }
        }
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,vis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
};