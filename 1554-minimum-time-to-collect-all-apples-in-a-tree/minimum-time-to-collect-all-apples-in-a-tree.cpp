class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&hasApple){
        int cnt=0;
        for(auto &it:adj[node]){
            if(it!=parent){
                cnt+=dfs(it,node,adj,hasApple);
            }
        }
        if(parent!=-1 && (cnt>0 || hasApple[node]))
        cnt+=2;
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=dfs(0,-1,adj,hasApple);
        return ans;
    }
};