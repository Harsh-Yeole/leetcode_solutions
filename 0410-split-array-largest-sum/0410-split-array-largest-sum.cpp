class Solution {
public:
    int check(int n,int k,int d,vector<int>&v){
        int cnt=0;
        int sum=0;
        int l=0;
        while(l<n){
            sum+=v[l];
            if(sum>d){
                sum=v[l];
                cnt++;
            }
            l++;
        }
        if(sum>0){
            cnt++;
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=0;
        for(int i=0;i<n;i++){
            high+=nums[i];
            low=max(low,nums[i]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(n,k,mid,nums)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};