class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=0,y=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2)
                y++;
                else
                x++;
                if(y>0){
                    if((x*b)<=(y*a))
                    ans++;
                }
            }
        }
        return ans;
    }
};