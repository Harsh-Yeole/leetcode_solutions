class Solution {
public:
    long long dfs(int n,int m,int i,int j,vector<vector<int>>&store,vector<vector<long long>>&mat,string &key,vector<vector<int>>&dp){
        if(j==m)
        return 0LL;
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long ret=INT_MAX;
        for(auto &it:store[key[j]-'a']){
            ret=min(ret,mat[i][it]+dfs(n,m,it,j+1,store,mat,key,dp)+1);
        }
        return dp[i][j]=ret;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>>store(26);
        vector<vector<long long>>mat(n,vector<long long>(n,INT_MAX));
        for(int i=0;i<n;i++){
            store[ring[i]-'a'].push_back(i);
            mat[i][i]=0;
            mat[i][(i-1+n)%n]=1LL;
            mat[i][(i+1)%n]=1LL;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dfs(n,m,0,0,store,mat,key,dp);
    }
};