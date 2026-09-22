class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0,n=nums.size();
        int l=0,r=0;
        while(r<n-1){
            int j=0;
            for(int k=l;k<=r;k++){
                j=max(j,k+nums[k]);
            }
            r=j;
            l=l+1;
            ans++;
        }
        return ans;
    }
};