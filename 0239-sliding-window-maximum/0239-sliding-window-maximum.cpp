class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            while(dq.size()>0){
                if((i-dq.front()+1)>k)
                dq.pop_front();
                else
                break;
            }
            while(!dq.empty()){
                int indx=dq.back();
                if(nums[indx]<=nums[i]){
                    dq.pop_back();
                }
                else{
                    break;
                }
            }
            dq.push_back(i);
            if(i>=k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};