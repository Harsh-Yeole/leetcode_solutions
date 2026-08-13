class Solution {
public:
    unordered_map<string, int> t;

    int solve(int i, int jump, int k, bool canJump, vector<long long>& power) {
        if (i > k + 1)
            return 0;

        string key = to_string(i) + "_" + to_string(jump) + "_" + to_string(canJump);

        if (t.find(key) != t.end())
            return t[key];

        int res = 0;

        if (i == k)
            res += 1;

        if (canJump) {
            res += solve(i - 1, jump, k, 0, power);
        }

        res += solve(i + power[jump], jump + 1, k, 1, power);

        return t[key] = res;
    }

    int waysToReachStair(int k) {
        vector<long long> power(32);
        for (int i = 0; i <= 31; i++) {
            power[i] = pow(2, i);
        }

        return solve(1, 0, k, 1, power);
    }
};