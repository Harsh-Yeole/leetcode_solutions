class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        vector<int>temp;
        int l=low,r=mid+1;
        int ret=0;
        for(int i=low;i<mid+1;i++){
            while(r<=high && nums[i]>2LL*nums[r])
            r++;
            ret+=r-(mid+1);
        }
        r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=0;i<temp.size();i++){
            nums[low+i]=temp[i];
        }
        return ret;
    }
    int mergesort(vector<int>&nums,int low,int high){
        if(low==high)
        return 0;
        int mid=(low+high)/2;
        int inversions=0;
        inversions+=mergesort(nums,low,mid);
        inversions+=mergesort(nums,mid+1,high);
        inversions+=merge(nums,low,mid,high);
        return inversions;
    }
    int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=mergesort(nums,low,high);
        return ans;
    }
};