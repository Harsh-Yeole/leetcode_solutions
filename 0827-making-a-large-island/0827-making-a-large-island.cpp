class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        while(x!=parent[x]){
            x=parent[x];
        }
        return parent[x];
    }
    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return;
        }
        int su=size[pu];
        int sv=size[pv];
        if(su<=sv){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
class Solution {
public:
    bool valid(int n,int x,int y){
        if(x<0 || y<0)
        return false;
        if(x>=n || y>=n)
        return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        DSU dsu(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int nodeindx=n*i+j;
                    ans=max(ans,dsu.size[nodeindx]);
                    vector<int>dr={-1,0,1,0};
                    vector<int>dc={0,-1,0,1};
                    for(int k=0;k<4;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(valid(n,x,y) && grid[x][y]==1){
                            int adjindx=n*x+y;
                            if(dsu.find(nodeindx)!=dsu.find(adjindx)){
                                dsu.unite(dsu.find(nodeindx),dsu.find(adjindx));
                                ans=max(ans,dsu.size[dsu.find(nodeindx)]);
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vector<int>dr={-1,0,1,0};
                    vector<int>dc={0,-1,0,1};
                    set<int>p;
                    for(int k=0;k<4;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(valid(n,x,y) && grid[x][y]==1){
                            int nodeindx=n*i+j;
                            int adjindx=n*x+y;
                            p.insert(dsu.find(adjindx));
                        }
                    }
                    int cal=1;
                    for(auto &it:p){
                        cal+=dsu.size[it];
                    }
                    ans=max(ans,cal);
                }
            }
        }
        return ans;
    }
};