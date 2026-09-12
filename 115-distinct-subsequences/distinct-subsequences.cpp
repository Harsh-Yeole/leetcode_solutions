class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[n][m]!=m)
        return 0;
        vector<vector<unsigned long long>>ans(n+1,vector<unsigned long long>(m+1,0LL));
        for(int i=1;i<=n;i++){
            if(s[i-1]==t[0])
            ans[i][1]=1LL;
        }
        for(int j=1;j<=m;j++){
            if(t[j-1]==s[0])
            ans[1][j]=1LL;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                ans[i][j]+=ans[i-1][j-1];
                if(dp[i][j]==dp[i-1][j])
                ans[i][j]+=ans[i-1][j];
                if(dp[i][j]==dp[i][j-1])
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans[n][m];
    }
};