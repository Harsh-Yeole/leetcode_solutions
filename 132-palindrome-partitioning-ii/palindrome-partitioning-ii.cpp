class Solution {
public:
    bool check(string &s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-1-i])
            return false;
        }
        return true;
    }
    int f(int n,string &s,int l,vector<int>&dp){
        if(l==n)
        return 0;
        if(dp[l]!=-1)
        return dp[l];
        string temp="";
        int ans=INT_MAX;
        for(int i=l;i<n;i++){
            temp+=s[i];
            if(check(temp)){
                int cal=1+f(n,s,i+1,dp);
                ans=min(ans,cal);
            }
        }
        return dp[l]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        vector<vector<int>>ispall(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j || (i==j+1 && s[i]==s[j]))
                ispall[j][i]=1;
                else{
                    if(s[i]==s[j])
                    ispall[j][i]=ispall[j+1][i-1];
                }
            }
        }
        for(int j=n-1;j>=0;j--){
            int ans=INT_MAX;
            string temp="";
            for(int i=j;i<n;i++){
                if(ispall[j][i]){
                    int cal=1+dp[i+1];
                    ans=min(ans,cal);
                }
            }
            dp[j]=ans;
        }
        return dp[0]-1;
    }
};