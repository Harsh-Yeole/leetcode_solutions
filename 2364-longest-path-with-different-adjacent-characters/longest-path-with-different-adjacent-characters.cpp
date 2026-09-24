class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>>&adj,int &ans,string &s){
        priority_queue<int>pq;
        int a=0,b=0;
        for(auto &it:adj[node]){
            if(it!=parent){
                if(s[it]!=s[node]){
                    int cal=dfs(it,node,adj,ans,s);
                    pq.push(cal);
                }
                else{
                    int cal=dfs(it,node,adj,ans,s);
                    ans=max(ans,cal);
                }
            }
        }
        if(pq.size()>0){
        a=pq.top();
        pq.pop();
        }
        if(pq.size()>0){
        b=pq.top();
        pq.pop();
        }
        ans=max(ans,a+b+1);
        return a+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>adj(n+1);
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans=0;
        dfs(0,-1,adj,ans,s);
        return ans;
    }
};