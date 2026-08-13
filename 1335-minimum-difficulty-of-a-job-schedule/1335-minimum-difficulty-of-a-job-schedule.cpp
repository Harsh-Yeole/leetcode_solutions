class Solution {
public:
    int f(int n,int indx,int days,vector<int>& jobDifficulty,vector<vector<int>>&dp){
        if(days==0){
            if(indx<n)
            return 1e7;
        }
        if(indx>=n){
            if(days==0)
            return 0;
            else
            return 1e8;
        }
        if(dp[indx][days]!=-1){
            return dp[indx][days];
        }
        int mx=0;
        int mn=INT_MAX;
        for(int i=indx;i<n;i++){
            mx=max(mx,jobDifficulty[i]);
            int cal=mx+f(n,i+1,days-1,jobDifficulty,dp);
            mn=min(mn,cal);
        }
        return dp[indx][days]=mn;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        int ans=f(n,0,d,jobDifficulty,dp);
        if(ans>=1e7)
        return -1;
        return ans;
    }
};