class Solution {
public:
    vector<int> f(int n,int i,vector<vector<int>>&adj){
        vector<int>ret;
        vector<int>visited(n,0);
        visited[i]=1;
        queue<int>q;
        int level=0;
        q.push(i);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                if(level!=0)
                ret.push_back(node);
                for(auto &it:adj[node]){
                    if(visited[it]!=1){
                        visited[it]=1;
                        q.push(it);
                    }
                }
            }
            level++;
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(auto &itr:edges){
            adj[itr[1]].push_back(itr[0]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(f(n,i,adj));
        }
        return ans;
    }
};