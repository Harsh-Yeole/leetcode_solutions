class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long cal=(1LL*nums[j]*nums[i]);
                long long temp=__gcd(nums[i],nums[j]);
                temp=(temp*temp);
                cal=cal/temp;
                ans=max(ans,cal);
            }
        }
        return ans;
    }
};