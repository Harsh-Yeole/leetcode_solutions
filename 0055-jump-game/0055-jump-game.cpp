class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),0),pre(nums.size()+1,0);
        int n=nums.size();
        dp[n-1]=1;
        pre[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int r=min(n,i+nums[i]+1);
            int cnt=pre[i+1]-pre[r];
            if(cnt>0){
                dp[i]=1;
                pre[i]=pre[i+1]+1;
            }
            else{
                dp[i]=0;
                pre[i]=pre[i+1];
            }
            //cout<<pre[i]<<" ";
        }
        //cout<<endl;
        return dp[0]==1;
    }
};