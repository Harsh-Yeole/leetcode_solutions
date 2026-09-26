class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>mat(26,vector<long long>(26,1e14));
        int n=original.size();
        for(int i=0;i<n;i++){
            long long u=original[i]-'a';
            long long v=changed[i]-'a';
            long long c=cost[i];
            mat[u][v]=min(mat[u][v],c);
        }
        for(int i=0;i<26;i++){
            mat[i][i]=0;
        }
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        long long ans=0LL;
        for(int i=0;i<source.size();i++){
            if(mat[source[i]-'a'][target[i]-'a']>=1e14)
            return -1;
            ans+=(mat[source[i]-'a'][target[i]-'a']);
        }
        if(ans>=1e14)
        return -1;
        return ans;
    }
};