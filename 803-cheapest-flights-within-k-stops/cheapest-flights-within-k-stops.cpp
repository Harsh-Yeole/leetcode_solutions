class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<vector<int>>>adj(n);
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int p=it[2];
            adj[u].push_back({v,p});
        }
        pq.push({0,0,src});
        while(!pq.empty()){
            vector<int>v=pq.top();
            pq.pop();
            int p=v[0];
            int s=v[1];
            int node=v[2];
            if(node==dst)
            return p;
            if(s>k)
            continue;
            for(auto &it:adj[node]){
                int cal=p+it[1];
                if(cal<dis[it[0]][s+1]){
                    dis[it[0]][s+1]=cal;
                    pq.push({cal,s+1,it[0]});
                }
            }
        }
        return -1;
    }
};