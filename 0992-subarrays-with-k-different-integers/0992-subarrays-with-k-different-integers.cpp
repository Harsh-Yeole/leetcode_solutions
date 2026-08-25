class Solution {
public:
    int count(int n,int k,vector<int>&nums){
        int cnt=0;
        int l=0,r=0;
        map<int,int>m;
        while(r<n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return count(n,k,nums)-count(n,k-1,nums);
    }
};