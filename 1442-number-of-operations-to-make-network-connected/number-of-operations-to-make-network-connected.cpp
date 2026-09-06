 class DSU{
        vector<int>parent;
        vector<int>rank;
        public:
        DSU(int n){
            parent.resize(n+1,0);
            rank.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int find(int i){
            if(parent[i]!=i)
            return parent[i]=find(parent[i]);
            return i;
        }
        void unionbyrank(int u,int v){
            int upu=find(u);
            int upv=find(v);
            if(upu==upv)
            return ;
            if(rank[upu]==rank[upv]){
                parent[upv]=upu;
                rank[upu]++;
            }
            else if(rank[upu]<rank[upv]){
                parent[upu]=upv;
            }
            else
            parent[upv]=upu;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total=connections.size();
        if(total<n-1)
        return -1;
        DSU dsu(n);
        for(auto &it:connections){
            dsu.unionbyrank(it[0],it[1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i)
            cnt++;
        }
        return cnt-1;
    }
};