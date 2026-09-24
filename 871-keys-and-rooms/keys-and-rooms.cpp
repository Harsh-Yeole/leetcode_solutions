class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt=0;
        int n=rooms.size();
        vector<int>visited(n+1,0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=1;
            cnt++;
            for(auto &it:rooms[node]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return cnt==n;
    }
};