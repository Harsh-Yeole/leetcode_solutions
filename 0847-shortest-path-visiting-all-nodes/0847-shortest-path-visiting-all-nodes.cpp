class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        set<pair<int,int>>s;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            int num=(1<<i);
            s.insert({i,num});
            q.push({i,num});
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++){
                pair<int,int>p=q.front();
                q.pop();
                if(p.second==(1<<n)-1)
                return ans-1;
                for(auto &it:graph[p.first]){
                    int num=(1<<it)|p.second;
                    if(s.find({it,num})==s.end()){
                        s.insert({it,num});
                        q.push({it,num});
                    }
                }
            }
        }
        return ans-1;
    }
};