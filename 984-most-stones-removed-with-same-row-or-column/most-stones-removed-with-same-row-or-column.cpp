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
        return ;
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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=20002;
        DSU dsu(n);
        int ans=0;
        for(auto &it:stones){
            dsu.unite(it[0],10000+it[1]+1);
        }
        set<int>s;
        for(auto &it:stones){
            int x=it[0];
            int y=10000+it[1]+1;
            s.insert(dsu.find(x));
            s.insert(dsu.find(y));
        }
        ans=(stones.size()-s.size());
        return ans;
    }
};