class Solution {
public:
    void dfs(int threshold,int node,vector<int> &visited,vector<vector<vector<int>>>&adj){
        visited[node]=1;
        for(auto &it:adj[node]){
            if(it[1]<=threshold && visited[it[0]]==0){
                dfs(threshold,it[0],visited,adj);
            }
        }
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int low=0,high=1e6;
        vector<vector<vector<int>>>adj(n);
        for(auto &it:edges){
            adj[it[1]].push_back({it[0],it[2]});
        }
        while(low<=high){
            int mid=(low+high)/2;
            vector<int>visited(n,0);
            dfs(mid,0,visited,adj);
            bool flag=true;
            for(int i=1;i<n;i++){
                if(visited[i]!=1){
                    flag=false;
                    break;
                }
            }
            if(flag){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        if(low>=1e6)
        return -1;
        return low;
    }
};