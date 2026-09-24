class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>>q;
        q.push({0});
        int n=graph.size();
        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
            int last=v.size()-1;
            if(v[last]==n-1)
            ans.push_back(v);
            else{
                for(auto &it:graph[v[last]]){
                    v.push_back(it);
                    q.push(v);
                    v.pop_back();
                }
            }
        }
        return ans;
    }
};