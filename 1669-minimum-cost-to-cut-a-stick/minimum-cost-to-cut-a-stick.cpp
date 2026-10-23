class Solution {
public:
    int f(int n,vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
        if(i+1==j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int cal=cuts[j]-cuts[i]+f(n,cuts,i,k,dp)+f(n,cuts,k,j,dp);
            ans=min(ans,cal);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        n=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(n,cuts,0,n-1,dp);
    }
};