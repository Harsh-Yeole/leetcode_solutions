class Solution {
public:
    bool check(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int j=n-1;j>=0;j--){
            int ans=INT_MAX;
            for(int i=j;i<n;i++){
                if(check(s,j,i)){
                    int cal=1+dp[i+1];
                    ans=min(ans,cal);
                }
            }
            dp[j]=ans;
        }
        return dp[0]-1;
    }
};