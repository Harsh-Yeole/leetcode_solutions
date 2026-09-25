class Solution {
public:
    vector<int> topo(int n,vector<int>&indegree,vector<vector<int>>&adj){
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return topo;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1)
            group[i]=m++;
        }
        vector<int>inorder(n,0),ig(m,0);
        vector<vector<int>>adj(n),adjg(m);
        for(int i=0;i<n;i++){
            for(auto &it:beforeItems[i]){
                inorder[i]++;
                adj[it].push_back(i);
                if(group[i]!=group[it]){
                    ig[group[i]]++;
                    adjg[group[it]].push_back(group[i]);
                }
            }
        }
        vector<int>topoele=topo(n,inorder,adj);
        vector<int>topog=topo(m,ig,adjg);
        if(topoele.size()!=n)
        return {};
        if(topog.size()!=m)
        return {};
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[group[topoele[i]]].push_back(topoele[i]);
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            for(auto &it:mp[topog[i]]){
                ans.push_back(it);
            }
        }
        return ans;
    }
};