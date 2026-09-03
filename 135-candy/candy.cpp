class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<pair<int,int>>store;
        for(int i=0;i<ratings.size();i++){
            store.push_back({ratings[i],i});
        }
        sort(store.begin(),store.end());
        vector<int>ans(ratings.size(),1);
        for(auto &it:store){
            int indx=it.second;
            int rat=0;
            if(indx-1>=0 && ratings[indx-1]<ratings[indx]){
                rat=max(rat,ans[indx-1]);
            }
            if(indx+1<=n-1 && ratings[indx+1]<ratings[indx]){
                rat=max(rat,ans[indx+1]);
            }
            ans[indx]=rat+1;
        }
        int sum=0;
        for(auto &it:ans){
            sum+=it;
        }
        return sum;
    }
};