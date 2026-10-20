class Solution {
public:
    int cal(int i,int j){
        if(j<=i)
        return i+1;
        else if((j-i)%2!=0)
        return j;
        else
        return j+1;
    }
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1)
        return -1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,INT_MAX));
        visited[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        while(!q.empty()){
                vector<int>temp=q.top();
                q.pop();
                int time=temp[0];
                int x=temp[1];
                int y=temp[2];
                if(x==m-1 && y==n-1)
                return time;
                if(x<m-1){
                    int ftime=cal(time,grid[x+1][y]);
                    if(visited[x+1][y]>ftime){
                        visited[x+1][y]=ftime;
                        q.push({ftime,x+1,y});
                    }
                }
                if(y<n-1){
                    int ftime=cal(time,grid[x][y+1]);
                    if(visited[x][y+1]>ftime){
                        visited[x][y+1]=ftime;
                        q.push({ftime,x,y+1});
                    }
                }
                if(x>0){
                    int ftime=cal(time,grid[x-1][y]);
                    if(visited[x-1][y]>ftime){
                        visited[x-1][y]=ftime;
                        q.push({ftime,x-1,y});
                    }
                }
                if(y>0){
                    int ftime=cal(time,grid[x][y-1]);
                    if(visited[x][y-1]>ftime){
                        visited[x][y-1]=ftime;
                        q.push({ftime,x,y-1});
                    }
                }
        }
        return -1;
    }
};