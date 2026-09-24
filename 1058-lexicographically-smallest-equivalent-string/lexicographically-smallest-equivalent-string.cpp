class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
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
        else{
            if(upu<upv){
                size[upu]+=size[upv];
                parent[upv]=upu;
            }
            else{
                size[upv]+=size[upu];
                parent[upu]=upv;
            }
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            dsu.unite(s1[i]-'a',s2[i]-'a');
        }
        for(auto &it:baseStr){
            int c=it-'a';
            c=dsu.find(c);
            char ch=c+'a';
            it=ch;
        }
        return baseStr;
    }
};