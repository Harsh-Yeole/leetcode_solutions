class Solution {
public:
    void dfs2(int n,int node,int parent,vector<vector<int>>&adj,vector<int>&ret,vector<int>&children){
        if(parent!=-1){
            int cal=ret[parent]-children[node]+(n-children[node]);
            ret[node]=cal;
        }
        for(auto &it:adj[node]){
            if(it!=parent)
            dfs2(n,it,node,adj,ret,children);
        }
    }
    int dfs1(int node,int parent,int dis,int &ans,vector<vector<int>>&adj,vector<int>&children){
        int cnt=1;
        ans+=dis;
        for(auto &it:adj[node]){
            if(it!=parent){
                cnt+=dfs1(it,node,dis+1,ans,adj,children);
            }
        }
        children[node]=cnt;
        return cnt;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ret(n+1,0);
        int ans=0;
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>children(n+1,0);
        dfs1(0,-1,0,ans,adj,children);
        ret[0]=ans;
        //cout<<ans<<endl;
        dfs2(n,0,-1,adj,ret,children);
        ret.pop_back();
        return ret;
    }
};