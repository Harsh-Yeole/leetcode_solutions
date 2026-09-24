class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>d1(n,n+1),d2=d1;
        vector<int>v1(n,0),v2=v1;
        queue<int>q;
        q.push(node1);
        int d=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            v1[node]=1;
            d1[node]=d;
            d++;
            int next=edges[node];
            if(next!=-1 && v1[next]==0)
            q.push(next);
        }
        d=0;
        q.push(node2);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            v2[node]=1;
            d2[node]=d;
            d++;
            int next=edges[node];
            if(next!=-1 && v2[next]==0)
            q.push(next);
        }
        int mn=n+1;
        int indx=-1;
        for(int i=0;i<n;i++){
            int mx=max(d1[i],d2[i]);
            if(mx<mn){
                mn=mx;
                indx=i;
            }
        }
        return indx;
    }
};