class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x)
        return parent[x]=find(parent[x]);
        return x;
    }
    void unite(int u,int v){
        int upu=find(u);
        int upv=find(v);
        if(upu==upv){
            return;
        }
        if(size[upu]>=size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        else{
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
    }
};
int kruskal(int n,vector<vector<int>>&v,int i,int j){
    DSU dsu(n);
    int cnt=0;
    if(j!=-1){
        dsu.unite(v[j][1],v[j][2]);
        cnt+=v[j][0];
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    for(int k=0;k<v.size();k++){
        if(k==i){
            continue;
        }
        int upu=dsu.find(v[k][1]);
        int upv=dsu.find(v[k][2]);
        if(upu!=upv){
            cnt+=v[k][0];
            dsu.unite(v[k][1],v[k][2]);
        }
    }
    bool flag=true;
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(dsu.find(i));
    }
    if(s.size()>1)
    return INT_MAX;
    else
    return cnt;
}
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       vector<vector<int>>v;
       for(int i=0;i<edges.size();i++){
        reverse(edges[i].begin(),edges[i].end());
        edges[i].push_back(i);
        v.push_back(edges[i]);
       }
       sort(v.begin(),v.end());
       int mn=kruskal(n,v,-1,-1);
       vector<int>c,pc;
       for(int i=0;i<v.size();i++){
        if(kruskal(n,v,i,-1)>mn)
        c.push_back(v[i][3]);
        else if(kruskal(n,v,-1,i)==mn)
        pc.push_back(v[i][3]);
       }
       return {c,pc};
    }
};