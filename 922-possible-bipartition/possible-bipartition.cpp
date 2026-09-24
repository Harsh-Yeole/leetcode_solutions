class Solution {
public:
    bool f(int node,int colour,vector<int>&visited,vector<vector<int>>&adj){
        visited[node]=colour;
        bool flag=true;
        for(auto &it:adj[node]){
            if(visited[it]==-1){
                if(!f(it,(1^colour),visited,adj))
                return false;
            }
            else{
                if(visited[it]==colour)
                return false;
            }
        }
        return flag;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        vector<int>visited(n+1,-1);
        for(auto &it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(visited[i]==-1)
            flag=flag&f(i,0,visited,adj);
        }
        return flag;
    }
};