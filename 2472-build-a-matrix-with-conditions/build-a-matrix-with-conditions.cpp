class Solution {
public:
    vector<int> topo(int n,vector<int>&indegree,vector<vector<int>>&adj){
        vector<int>ret;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                ret.push_back(node);
                for(auto &it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0)
                    q.push(it);
                }
            }
        }
        return ret;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>indegree(k+1,0),indegreec(k+1,0);
        vector<vector<int>>adj(k+1),adjc(k+1);
        for(auto &it:rowConditions){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        for(auto &it:colConditions){
            indegreec[it[1]]++;
            adjc[it[0]].push_back(it[1]);
        }
        vector<int>toporow=topo(k,indegree,adj);
        if(toporow.size()<k)
        return {};
        vector<int>topocol=topo(k,indegreec,adjc);
        if(topocol.size()<k)
        return {};
        vector<vector<int>>ans(k,vector<int>(k,0));
        map<int,int>m;
        for(int i=0;i<k;i++){
            m[toporow[i]]=i;
        }
        for(int i=0;i<k;i++){
            ans[m[topocol[i]]][i]=topocol[i];
        }
        return ans;
    }
};