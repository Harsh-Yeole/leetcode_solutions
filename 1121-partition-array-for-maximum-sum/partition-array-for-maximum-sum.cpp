class Solution {
public:
    long long f(int n,vector<int>&arr,int i,int k,vector<int>&dp){
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        long long mx=0LL;
        long long ret=-1e12;
        for(int j=i;j<n;j++){
            mx=max(mx,arr[j]*1LL);
            if(j-i+1<=k){
                long long cal=(j-i+1)*mx+f(n,arr,j+1,k,dp);
                ret=max(ret,cal);
            }
            else
            break;
        }
        return dp[i]=ret;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long mx=0LL;
            long long ret=-1e12;
            for(int j=i;j<n;j++){
                mx=max(mx,arr[j]*1LL);
                if(j-i+1<=k){
                    long long cal=(j-i+1)*mx+dp[j+1];
                    ret=max(ret,cal);
                }
                else
                break;
            }
            dp[i]=ret;
        }
        return (int)dp[0];
    }
};