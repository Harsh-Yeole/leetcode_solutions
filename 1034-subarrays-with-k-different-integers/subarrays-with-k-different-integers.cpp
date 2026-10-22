class Solution {
public:
    int cnt(int n,vector<int>&nums,int k){
        vector<int>v(n+1,0);
        int l=0,r=0,sum=0,ret=0;
        while(r<n){
            if(v[nums[r]]++==0){
                sum++;
            }
            while(l<=r && sum>=k){
                ret+=(n-r);
                if(--v[nums[l]]==0){
                    sum--;
                }
                l++;
            }
            r++;
        }
        return ret;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return cnt(n,nums,k)-cnt(n,nums,k+1);
    }
};