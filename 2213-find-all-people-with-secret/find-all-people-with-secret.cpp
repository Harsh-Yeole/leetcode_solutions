class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<vector<int>>>adj(n);
        for(auto &it:meetings){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]}); 
        }
        vector<int>know(n,INT_MAX);
        know[0]=0;
        know[firstPerson]=0;
        pq.push({0,0});
        pq.push({0,firstPerson});
        set<int>ans;
        while(!pq.empty()){
            vector<int>v=pq.top();
            pq.pop();
            int node=v[1];
            int time=v[0];
            ans.insert(node);
            if(time<=know[node]){
                for(auto &it:adj[node]){
                    if(time<=it[1] && know[it[0]]>it[1]){
                        know[it[0]]=it[1];
                        pq.push({it[1],it[0]});
                    }
                }
            }
        }
        vector<int>ret;
        for(auto &it:ans){
            ret.push_back(it);
        }
        return ret;
    }
};