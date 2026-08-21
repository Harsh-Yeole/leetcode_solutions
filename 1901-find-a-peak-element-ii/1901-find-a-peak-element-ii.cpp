class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int indx=0;
            int mx=mat[0][mid];
            for(int j=0;j<m;j++){
                if(mat[j][mid]>mx){
                    mx=mat[j][mid];
                    indx=j;
                }
            }
            if(mid>0 && mat[indx][mid-1]>mat[indx][mid])
            high=mid-1;
            else if(mid<n-1 && mat[indx][mid+1]>mat[indx][mid])
            low=mid+1;
            else
            return {indx,mid};
        }
        return {-1,-1};
    }
};