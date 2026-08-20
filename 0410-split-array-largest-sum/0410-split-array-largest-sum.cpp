class Solution {
public:
    bool check(int n,int k,int mid,vector<int>&v){
        int cnt=0;
        int sum=0;
        int l=0;
        while(l<n){
            if(v[l]>mid)return false;
            sum+=v[l];
            if(sum>mid){
                sum=v[l];
                cnt++;
            }
            l++;
        }
        if(sum>0){
            cnt++;
        }
        if(cnt<=k)return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=0;
        for(int i=0;i<n;i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n,k,mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};