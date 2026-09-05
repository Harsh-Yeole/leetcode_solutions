class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            if(v.size()==0){
                v.push_back(intervals[i]);
                continue;
            }
            else{
                int indx=v.size()-1;
                if(v[indx][1]>=intervals[i][0])
                v[indx][1]=max(v[indx][1],intervals[i][1]);
                else{
                    v.push_back(intervals[i]);
                }
            }
        }
        return v;
    }
};