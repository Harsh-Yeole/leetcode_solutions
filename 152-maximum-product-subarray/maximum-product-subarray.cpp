class Solution {
public:
    long long dac(vector<int>&nums,int low,int high){
        /*if(high<low)
        return INT_MIN;*/
        if(high==low)
        return nums[low]*1LL;
        int mid=(low+high)/2;
        long long left=dac(nums,low,mid);
        long long right=dac(nums,mid+1,high);
        long long lmax=nums[mid],lmin=nums[mid],curr=nums[mid];
        for(int i=mid-1;i>=low;i--){
            curr=curr*nums[i];
            lmax=max(lmax,curr);
            lmin=min(lmin,curr);
        }
        long long rmax=INT_MIN,rmin=INT_MAX;
        curr=1LL;
        for(int i=mid+1;i<=high;i++){
            curr=curr*nums[i];
            rmax=max(rmax,curr);
            rmin=min(rmin,curr);
        }
        return max({left,right,
        lmax*rmax,
        lmin*rmin,
        lmax*rmin,
        lmin*rmax});
    }
    int maxProduct(vector<int>& nums) {
        long long ans=dac(nums,0,nums.size()-1);
        return (int)ans;
    }
};