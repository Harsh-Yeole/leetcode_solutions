class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<int>t;
        vector<int>t1,t2;
        vector<vector<int>>ans;
        for(auto it:series1){
            t1.push_back(it[0]);
            t.insert(it[0]);
        }
        for(auto it:series2){
            t2.push_back(it[0]);
            t.insert(it[0]);
        }
        for(auto &it:t){
            int sum=0;
            int indx1=lower_bound(t1.begin(),t1.end(),it)-t1.begin();
            int indx2=lower_bound(t2.begin(),t2.end(),it)-t2.begin();
            if(indx1<series1.size()){
                sum+=series1[indx1][1];
            }
            if(indx2<series2.size()){
                sum+=series2[indx2][1];
            }
            ans.push_back({it,sum});
        }
        return ans;
    }
};