class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>v(n,vector<int>(26,0));
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        int cnt=0,ans=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            v[node][colors[node]-'a']++;
            ans=max(ans,v[node][colors[node]-'a']);
            for(auto &it:adj[node]){
                for(int j=0;j<26;j++){
                    v[it][j]=max(v[it][j],v[node][j]);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt<n)
        return -1;
        return ans;
    }
};