class Solution {
public:
    void f(vector<int>&ans,vector<int>&tasks,vector<int>& shift,vector<long long>&pre,int ind,int start,int end,long long prev){
        if(ind>=shift.size())
        return;
        long long target=1LL*shift[ind]+prev;
        int ti=upper_bound(pre.begin()+start,pre.end(),target)-pre.begin();
        cout<<ti<<endl;
        if(ti>=pre.size()){
            ans.push_back(0);
            return f(ans,tasks,shift,pre,ind+1,0,end,0);
        }
        int temp=end-ti+1;
        ans.push_back(temp);
        long long extra=0LL;
        if(ti>0){
            extra=pre[ti-1];
        }
        extra=target-extra;
        if(ti>0){
            extra+=pre[ti-1];
        }
        return f(ans,tasks,shift,pre,ind+1,ti,end,extra);
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<int>ans;
        vector<long long>pre;
        long long sum=0;
        for(int i=0;i<tasks.size();i++){
            sum+=(tasks[i]);
            pre.push_back(sum);
        }
        f(ans,tasks,shifts,pre,0,0,pre.size()-1,0);
        return ans;
    }
};