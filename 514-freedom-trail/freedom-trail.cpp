class Solution {
public:
    int mindis(int i,int j,int n){
        int dis=abs(i-j);
        dis=min(dis,n-dis);
        return dis;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>>store(26);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        vector<vector<int>> dist(n, vector<int>(m + 1, 1e9));
        for(int i=0;i<n;i++){
            store[ring[i]-'a'].push_back(i);
        }
        q.push({0,0,0});
        dist[0][0]=0;
        while(!q.empty()){
            vector<int>v=q.top();
            q.pop();
            int i=v[1];
            int j=v[2];
            int step=v[0];
            if(j==m)
            return m+step;
            for(auto &it:store[key[j]-'a']){
                int cal=mindis(i,it,n)+step;
                if(dist[it][j+1]>cal){
                    dist[it][j+1]=cal;
                    q.push({cal,it,j+1});
                }
            }
        }
        return -1;
    }
};