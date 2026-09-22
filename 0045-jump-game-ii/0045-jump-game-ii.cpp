class Solution {
public:
    int f(int n,int i,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()-1)
        return 0;
        if(nums[i]==0)
        return 1e5;
        if(dp[i]!=-1)
        return dp[i];
        int mn=1e5;
        for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
            int cal=1+f(n,j,nums,dp);
            mn=min(mn,cal);
        }
        return dp[i]=mn;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n,0,nums,dp);
    }
};