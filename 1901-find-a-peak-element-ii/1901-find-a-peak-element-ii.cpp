class Solution {
public:
    pair<int,int> peak(int m,int n,int r,int c,vector<vector<int>>&mat){
        int mx=mat[r][c];
        int i=r,j=c;
        if(r<m-1){
            if(mat[r+1][c]>mx){
                mx=mat[r+1][c];
                i=r+1;
                j=c;
            }
        }
        if(c<n-1){
            if(mat[r][c+1]>mx){
                mx=mat[r][c+1];
                i=r;
                j=c+1;
            }
        }
        if(r>0){
            if(mat[r-1][c]>mx){
                mx=mat[r-1][c];
                i=r-1;
                j=c;
            }
        }
        if(c>0){
            if(mat[r][c-1]>mx){
                mx=mat[r][c-1];
                i=r;
                j=c-1;
            }
        }
        return {i,j};
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int r=0,c=n-1;
        while(r<m && c>=0){
            pair<int,int>p=peak(m,n,r,c,mat);
            int i=p.first;
            int j=p.second;
            if(i==r && j==c)
            return {r,c};
            else if(i==r-1 && j==c){
                r=r-1;
            }
            else if(i==r+1 && j==c)
            r=r+1;
            else if(i==r && j==c-1)
            c=c-1;
            else if(i==r && j==c+1)
            c=c+1;
        }
        return {-1,-1};
    }
};