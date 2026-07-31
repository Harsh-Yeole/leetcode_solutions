class DSU{
    public:
        vector<int>parent;
        vector<int>rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n+1,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int x){
            if(x!=parent[x]){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        void unite(int u,int v){
            int pu=find(u);
            int pv=find(v);
            if(pu==pv)
            return;
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }
            else if(rank[pv]<rank[pu]){
                parent[pv]=pu;
            }
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        DSU dsu(n);
        for(auto it:connections){
            dsu.unite(it[0],it[1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            dsu.find(i);
            if(dsu.parent[i]==i){
                cnt++;
            }
        }
        return cnt-1;
    }
};