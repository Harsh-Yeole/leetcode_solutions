class Solution {
public:
    bool dfs(int node,vector<int>&dis,vector<vector<vector<int>>>&adj,vector<bool>&ans,vector<int>&dp){
        if(node==0)
        return true;
        if(dp[node]!=-1)
        return dp[node];
        bool flag=false;
        for(auto &it:adj[node]){
            int v=it[0];
            int wt=it[1];
            int indx=it[2];
            if(dis[v]==dis[node]-wt){
                ans[indx]=dfs(v,dis,adj,ans,dp);
                flag=flag|ans[indx];
            }
        }
        return dp[node]=flag;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int>dis(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<vector<int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w,i});
            adj[v].push_back({u,w,i});
        }
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty()){
            vector<int>vec=pq.top();
            pq.pop();
            int node=vec[1];
            int cal=vec[0];
            if(cal>dis[node])
            continue;
            for(auto &it:adj[node]){
                int v=it[0];
                int wt=it[1];
                if(dis[v]>wt+cal){
                    dis[v]=wt+cal;
                    pq.push({dis[v],v});
                }
            }
        }
        vector<int>dp(n,-1);
        vector<bool>ans(edges.size(),0);
        dfs(n-1,dis,adj,ans,dp);
        return ans;
    }
};