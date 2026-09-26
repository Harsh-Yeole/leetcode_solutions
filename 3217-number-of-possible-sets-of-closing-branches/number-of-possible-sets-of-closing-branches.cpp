class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            vector<vector<int>>mat(n,vector<int>(n,1e5+1));
            for(auto &it:roads){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(((i>>u)&1) && ((i>>v)&1)){
                    mat[u][v]=min(mat[u][v],w);
                    mat[v][u]=min(mat[v][u],w);
                }
            }
            for(int j=0;j<n;j++){
                mat[j][j]=0;
            }
            for(int via=0;via<n;via++){
                for(int u=0;u<n;u++){
                    for(int v=0;v<n;v++){
                        mat[u][v]=min(mat[u][v],mat[u][via]+mat[via][v]);
                    }
                }
            }
            bool flag=true;
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    if(u==v)
                    continue;
                    if(((i>>u)&1) && ((i>>v)&1)){
                        if(mat[u][v]>maxDistance){
                            flag=false;
                            break;
                        }
                    }
                }
            }
            if(flag)
            ans++;
        }
        return ans;
    }
};