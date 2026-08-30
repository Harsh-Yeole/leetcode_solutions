class Solution {
public:
    int N = 1e9 + 7;

    int cmx(int i, int j, int n, vector<string>& board, vector<vector<int>>& dp1, vector<vector<int>>& dp2) {
        // Base case: we reached the destination
        if (i == 0 && j == 0) {
            return dp2[0][0] = 1;
        }
        if (dp2[i][j] != -1)
            return dp2[i][j];
            
        int tsum = 0;
        int val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');

        // Explore paths that mathematically equal the max score route
        if (i - 1 >= 0 && board[i - 1][j] != 'X') {
            if (dp1[i][j] == val + dp1[i - 1][j]) {
                tsum = (tsum + cmx(i - 1, j, n, board, dp1, dp2)) % N;
            }
        }
        if (j - 1 >= 0 && board[i][j - 1] != 'X') {
            if (dp1[i][j] == val + dp1[i][j - 1]) {
                tsum = (tsum + cmx(i, j - 1, n, board, dp1, dp2)) % N;
            }
        }
        if (j - 1 >= 0 && i - 1 >= 0 && board[i - 1][j - 1] != 'X') {
            if (dp1[i][j] == val + dp1[i - 1][j - 1]) {
                tsum = (tsum + cmx(i - 1, j - 1, n, board, dp1, dp2)) % N;
            }
        }
        return dp2[i][j] = tsum;
    }

    int fmx(int i, int j, int n, vector<string>& board, vector<vector<int>>& dp) {
        // Fix: Save the base case 0 into the DP table so cmx can read it later
        if (i == 0 && j == 0)
            return dp[0][0] = 0;
            
        if (dp[i][j] != -1)
            return dp[i][j];
            
        int max_val = -1e5; // Use a large negative number to represent 'unreachable'

        if (i - 1 >= 0 && board[i - 1][j] != 'X') {
            max_val = max(max_val, fmx(i - 1, j, n, board, dp));
        }
        if (j - 1 >= 0 && board[i][j - 1] != 'X') {
            max_val = max(max_val, fmx(i, j - 1, n, board, dp));
        }
        if (j - 1 >= 0 && i - 1 >= 0 && board[i - 1][j - 1] != 'X') {
            max_val = max(max_val, fmx(i - 1, j - 1, n, board, dp));
        }

        // If all paths were blocked, keep this cell blocked
        if (max_val < 0) 
            return dp[i][j] = -1e5;
            
        int val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
        return dp[i][j] = val + max_val;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        
        // DP1: Find maximum score from any (i, j) to (0, 0)
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int ans = fmx(n - 1, n - 1, n, board, dp1);
        
        // If the destination is unreachable, return [0, 0]
        if (ans < 0) {
            return {0, 0};
        }
        
        // DP2: Count how many paths follow the max scores mapped in DP1
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int ans2 = cmx(n - 1, n - 1, n, board, dp1, dp2);
        
        return {ans, ans2};
    }
};