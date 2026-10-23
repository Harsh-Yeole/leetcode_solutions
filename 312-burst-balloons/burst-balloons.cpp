class Solution {
public:
    int f(vector<int>&nums,int low,int high,vector<vector<int>>&dp){
        if(dp[low][high]!=-1)
        return dp[low][high];
        int ans=0;
        for(int i=low+1;i<high;i++){
            int cal=nums[low]*nums[i]*nums[high];
            cal+=f(nums,low,i,dp);
            cal+=f(nums,i,high,dp);
            ans=max(ans,cal);
        }
        return dp[low][high]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(nums,0,n-1,dp);
    }
};