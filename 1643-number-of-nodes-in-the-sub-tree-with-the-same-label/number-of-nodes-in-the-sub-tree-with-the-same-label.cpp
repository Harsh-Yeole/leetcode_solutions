class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&dp,string &labels,vector<int>&ans){
        int prev=dp[labels[node]-'a'];
        dp[labels[node]-'a']++;
        for(auto &it:adj[node]){
            if(it!=parent){
                dfs(it,node,adj,dp,labels,ans);
            }
        }
        int cnt=dp[labels[node]-'a']-prev;
        ans[node]=cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>dp(26,0);
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,0);
        dfs(0,-1,adj,dp,labels,ans);
        return ans;
    }
};