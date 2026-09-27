class Solution {
public:
    int findRotateSteps(string ring, string key) {
        queue<vector<int>>q;
        int n=ring.size(),m=key.size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        q.push({0,0,0});
        while(!q.empty()){
            int size=q.size();
                for(int k=0;k<size;k++){
                vector<int>v=q.front();
                q.pop();
                if(v[2]==m)
                return v[0];
                int step=v[0];
                int i=v[1];
                int j=v[2];
                if(ring[i]==key[j]){
                    q.push({step+1,i,j+1});
                    continue;
                }
                if(visited[(i+1)%n][j]==0){
                    visited[(i+1)%n][j]=1;
                    q.push({step+1,(i+1)%n,j});
                }
                if(visited[(i-1+n)%n][j]==0){
                    visited[(i-1+n)%n][j]=1;
                    q.push({step+1,(i-1+n)%n,j});
                }
            }
        }
        return -1;
    }
};