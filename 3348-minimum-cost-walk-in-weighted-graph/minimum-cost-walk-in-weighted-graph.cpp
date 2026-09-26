class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,(1<<20)-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x!=parent[x])
        return parent[x]=find(parent[x]);
        return x;
    }
    void unite(int u,int v,int price){
        int upu=find(u);
        int upv=find(v);
        if(upu==upv){
            size[upu]=(size[upu]&price);
            return;
        }
        if(size[upu]>=size[upv]){
            size[upu]=(size[upu]&size[upv]&price);
            parent[upv]=upu;
        }
        else{
            size[upv]=(size[upv]&size[upu]&price);
            parent[upu]=upv;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto &it:edges){
            dsu.unite(it[0],it[1],it[2]);
        }
        vector<int>ans;
        for(auto &it:query){
            int u=it[0];
            int v=it[1];
            int upu=dsu.find(u);
            int upv=dsu.find(v);
            if(upu!=upv){
                ans.push_back(-1);
                continue;
            }
            else{
                ans.push_back(dsu.size[upu]);
            }
        }
        return ans;
    }
};