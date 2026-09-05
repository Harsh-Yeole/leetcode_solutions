class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        int n=intervals.size();
        int i=0;
        bool flag=false;
        if(n>0 && newInterval[1]<intervals[i][0]){
            v.push_back(newInterval);
            flag=true;
        }
        while(i<n){
            if(intervals[i][1]<newInterval[0]){
                v.push_back(intervals[i]);
                i++;
            }
            else if(intervals[i][0]>newInterval[1]){
                if(flag==false){
                    v.push_back(newInterval);
                    flag=true;
                }
                v.push_back(intervals[i]);
                i++;
            }
            else{
                while(i<n){
                    if(intervals[i][1]<=newInterval[0]){
                        newInterval[0]=min(newInterval[0],intervals[i][0]);
                        newInterval[1]=max(newInterval[1],intervals[i][1]);
                        i++;
                    }
                    else if(intervals[i][0]<=newInterval[1]){
                        newInterval[0]=min(newInterval[0],intervals[i][0]);
                        newInterval[1]=max(newInterval[1],intervals[i][1]);
                        i++;
                    }
                    else
                    break;
                } 
                v.push_back(newInterval);
                flag=true;
            }
        }
        if(!flag)
        v.push_back(newInterval);
        return v;
    }
};