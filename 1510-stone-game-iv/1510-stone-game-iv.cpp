class Solution {
public:
    bool f(int n,int chance,vector<int>&squares,vector<vector<int>>&dp){
        if(n==0){
            return false;
        }
        if(dp[n][chance]!=-1)
        return dp[n][chance];
        int indx=upper_bound(squares.begin(),squares.end(),n)-squares.begin();
        bool flag=false;
        for(int i=0;i<indx;i++){
            flag=flag|(!f(n-squares[i],(chance^1),squares,dp));
        }
        return dp[n][chance]=flag;
    }
    bool winnerSquareGame(int n) {
        vector<int>squares;
       for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
       } 
       vector<vector<int>>dp(1e5+1,vector<int>(2,-1));
       return f(n,0,squares,dp);
    }
};