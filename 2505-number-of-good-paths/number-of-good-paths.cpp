class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x)
        return parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int u,int v){
        int upu=find(u);
        int upv=find(v);
        if(upu==upv)
        return;
        if(size[upu]>=size[upv]){
            size[upu]+=size[upv];
            parent[upv]=upu;
        }
        else{
            size[upv]+=size[upu];
            parent[upu]=upv;
        }
    }

};
int nc2(int n){
    if(n<2)
    return 0;
    int cal=(n*(n-1))/2;
    return cal;
}
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int ans=0;
        map<int,vector<int>>m;
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            m[vals[i]].push_back(i);
        }
        DSU dsu(n);
        vector<int>active(n,0);
        for(auto &it:m){
            for(auto &itr:it.second){
                active[itr]=1;
                for(auto v:adj[itr]){
                    if(active[v]){
                        dsu.unite(v,itr);
                    }
                }
            }
            unordered_map<int,int>um;
            for(auto &itr:it.second){
               um[dsu.find(itr)]++;
            }
            int cal=0;
            for(auto &itr:um){
                cal+=nc2(itr.second);
            }
            ans+=cal;
        }
        return ans+n;
    }
};