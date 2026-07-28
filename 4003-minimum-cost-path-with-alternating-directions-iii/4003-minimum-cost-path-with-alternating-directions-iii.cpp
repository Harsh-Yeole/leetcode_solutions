class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        vector<vector<vector<long long>>>adj(m,vector<vector<long long>>(n,vector<long long>(2,1e18)));
        pq.push({1*1LL,0*1LL,0*1LL,1*1LL});
        adj[0][0][1]=1;
        while(!pq.empty()){
            long long val=pq.top()[0];
            long long i=pq.top()[1];
            long long j=pq.top()[2];
            long long chance=pq.top()[3];
            pq.pop();
            if(i==m-1 && j==n-1)
            return val;
            if(adj[i][j][1-chance]>val+penalty[i][j]){
                adj[i][j][1-chance]=val+penalty[i][j];
                pq.push({val+penalty[i][j],i,j,1-chance});
            }
            if(i>0){
                if(chance==0){
                    long long cal=(val+(i*(j+1)));
                    if(cal<adj[i-1][j][1]){
                        adj[i-1][j][1]=cal;
                        pq.push({cal,i-1,j,1});
                    }
                }
                else{
                    long long cal=penalty[i][j]+(val+(i*(j+1)));
                    if(cal<adj[i-1][j][0]){
                        adj[i-1][j][0]=cal;
                        pq.push({cal,i-1,j,0});
                    }
                }
            }
            if(j>0){
                if(chance==0){
                    long long cal=(val+(j*(i+1)));
                    if(cal<adj[i][j-1][1]){
                        adj[i][j-1][1]=cal;
                        pq.push({cal,i,j-1,1});
                    }
                }
                else{
                    long long cal=penalty[i][j]+(val+(j*(i+1)));
                    if(cal<adj[i][j-1][0]){
                        adj[i][j-1][0]=cal;
                        pq.push({cal,i,j-1,0});
                    }
                }
            }
            if(i<m-1){
                 if(chance==0){
                    long long cal=penalty[i][j]+(val+(i+2)*(j+1));
                    if(cal<adj[i+1][j][1]){
                        adj[i+1][j][1]=cal;
                        pq.push({cal,i+1,j,1});
                    }
                }
                else{
                    long long cal=(val+(i+2)*(j+1));
                    if(cal<adj[i+1][j][0]){
                        adj[i+1][j][0]=cal;
                        pq.push({cal,i+1,j,0});
                    }
                }
            }
            if(j<n-1){
                if(chance==0){
                    long long cal=penalty[i][j]+(val+(j+2)*(i+1));
                    if(cal<adj[i][j+1][1]){
                        adj[i][j+1][1]=cal;
                        pq.push({cal,i,j+1,1});
                    }
                }
                else{
                    long long cal=(val+(j+2)*(i+1));
                    if(cal<adj[i][j+1][0]){
                        adj[i][j+1][0]=cal;
                        pq.push({cal,i,j+1,0});
                    }
                }
            }
        }
        return min(adj[m-1][n-1][1],adj[m-1][n-1][1]);
    }
};