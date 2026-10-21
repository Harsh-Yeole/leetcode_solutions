class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=0,ele2=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1++;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            cnt1++;
            else if(nums[i]==ele2)
            cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto &it:nums){
            if(it==ele1)
            cnt1++;
            else if(it==ele2)
            cnt2++;
        }
        int cnt=nums.size()/3;
        vector<int>ans;
        if(cnt1>cnt)
        ans.push_back(ele1);
        if(cnt2>cnt)
        ans.push_back(ele2);
        return ans;
    }
};