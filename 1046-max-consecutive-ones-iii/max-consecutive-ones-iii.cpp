class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,ans=0,cnt=0,temp=0;
        while(r<n){
            if(nums[r]==1){
                ans=max(ans,r-l+1);
            }
            else{
                cnt++;
                while(l<=r && cnt>k){
                    if(nums[l]==0){
                        cnt--;
                        l++;
                    }
                    else{
                        l++;
                    }
                }
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};