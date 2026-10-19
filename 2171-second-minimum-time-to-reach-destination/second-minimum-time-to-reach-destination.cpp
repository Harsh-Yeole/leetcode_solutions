class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dis1(n+1,INT_MAX),dis2=dis1,freq(n+1,0);
        dis1[1]=0;
        pq.push({0,1});
        int ans=INT_MAX;
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int tame=p.first;
            int node=p.second;
            freq[node]++;
            if(freq[node]==2 && node==n)
            return tame;
            if ((tame / change) % 2) {
                tame = change * (tame / change + 1) + time;
            } else {
                tame = tame + time;
            }
            for(auto &it:adj[node]){
                if(freq[it]>=2)
                continue;
                else{
                    if(dis1[it]>tame){
                        dis2[it]=dis1[it];
                        dis1[it]=tame;
                        pq.push({tame,it});
                    }
                    else if(dis2[it]>tame && dis1[it]!=tame){
                        dis2[it]=tame;
                        pq.push({tame,it});
                    }
                }
            }
        }
        return 0;
    }
};