class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid>0 && nums[mid-1]>nums[mid])
            high=mid-1;
            else if(mid<n-1 && nums[mid+1]>nums[mid])
            low=mid+1;
            else
            return mid;
        }
        return -1;
    }
};