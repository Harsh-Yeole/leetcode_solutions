class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<vector<int>>q;
        q.push({0,entrance[0],entrance[1]});
        vector<vector<int>>visited(m,vector<int>(n,0));
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
            int step=v[0];
            int x=v[1];
            int y=v[2];
            if(x!=entrance[0] || y!=entrance[1]){
                if(x==0 || x==m-1 || y==0 || y==n-1)
                return step;
            }
            visited[x][y]=1;
            if(x>0 && maze[x-1][y]!='+' && visited[x-1][y]==0){
                q.push({step+1,x-1,y});
                visited[x-1][y]=1;
            }
            if(x<m-1 && maze[x+1][y]!='+' && visited[x+1][y]==0){
                q.push({step+1,x+1,y});
                visited[x+1][y]=1;
            }
            if(y<n-1 && maze[x][y+1]!='+' && visited[x][y+1]==0){
                q.push({step+1,x,y+1});
                visited[x][y+1]=1;
            }
            if(y>0 && maze[x][y-1]!='+' && visited[x][y-1]==0){
                q.push({step+1,x,y-1});
                visited[x][y-1]=1;
            }
        }
        return -1;
    }
};