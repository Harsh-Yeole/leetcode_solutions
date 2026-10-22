class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         map<int,int>m;
         int sum=0;
         int ans=0;
         m[0]++;
         for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int comp=sum-k;
            ans+=m[comp];
            m[sum]++;
         }
         return ans;
    }
};