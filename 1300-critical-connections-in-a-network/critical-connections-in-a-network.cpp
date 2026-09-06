class Solution {
public:
    void dfs(vector<vector<int>>&ans,int &t,int node,int parent,vector<int>&visited,vector<int>&time,vector<int>&low,vector<vector<int>>&connections){
        time[node]=t;
        low[node]=t;
        visited[node]=1;
        for(auto &it:connections[node]){
            if(it!=parent){
                if(visited[it]){
                    low[node]=min(low[node],low[it]);
                }
                else{
                    t++;
                    dfs(ans,t,it,node,visited,time,low,connections);
                    low[node]=min(low[node],low[it]);
                    if(low[it]>time[node])
                    ans.push_back({node,it});
                }
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>visited(n+1,0);
        vector<int>time(n+1,INT_MAX);
        vector<int>low(n+1,INT_MAX);
        int t=0;
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(ans,t,0,-1,visited,time,low,adj);
        return ans;
    }
};