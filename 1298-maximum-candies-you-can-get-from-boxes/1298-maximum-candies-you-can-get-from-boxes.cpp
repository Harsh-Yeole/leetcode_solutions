class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        queue<int>q;
        vector<int>posn(n,0);
        vector<int>k(n,0);
        vector<int>open(n,0);
        for(auto &it:initialBoxes){
            if(status[it]==1)
            q.push(it);
            posn[it]=1;
        }
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(open[node]==1)
            continue;
            ans+=candies[node];
            open[node]=1;
            for(auto &it:keys[node]){
                k[it]=1;
            }
            for(auto &it:containedBoxes[node]){
                posn[it]=1;
            }
            for(int i=0;i<n;i++){
                if(open[i]==0){
                    if(posn[i]==1 && ((status[i]==1)||(k[i]==1)))
                    q.push(i);
                }
            }
        }
        return ans;
    }
};