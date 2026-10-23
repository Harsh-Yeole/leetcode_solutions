int dp[2001];
class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start<end) {
            if (s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        memset(dp,0,sizeof(int)*(n+1));
        for (int i=n-1; i>=0; i--) {
            int mini = n;
            for (int k=i; k<n; k++) {
                if (isPalindrome(s,i,k)) mini = min(mini, 1+dp[k+1]);
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};