#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // Helper to check 1 character difference
    bool check(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }

    vector<vector<string>> dfs(int n, int i, vector<vector<vector<string>>>& dp, vector<string>& wordList, vector<int>& dis, vector<bool>& visited, unordered_map<string, int>& um) {
        // Base Case: Reached beginWord (placed at index n - 1)
        if (i == n - 1)
            return {{wordList[i]}};

        // Cache dead-ends and visited results
        if (visited[i]) {
            return dp[i];
        }
        visited[i] = true;

        vector<vector<string>> ret;
        string word = wordList[i];

        // O(26 * L) character mutation lookup using 'um'
        for (int k = 0; k < word.size(); k++) {
            string wordCopy = word;
            for (char c = 'a'; c <= 'z'; c++) {
                wordCopy[k] = c;
                if (um.count(wordCopy)) {
                    int j = um[wordCopy];
                    if (dis[j] == dis[i] - 1) {
                        vector<vector<string>> temp;
                        temp = dfs(n, j, dp, wordList, dis, visited, um);
                        
                        // Copy 'it' by value to prevent corrupting memoized dp results
                        for (auto it : temp) {
                            it.push_back(wordList[i]);
                            ret.push_back(it);
                        }
                    }
                }
            }
        }

        return dp[i] = ret;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Verify endWord exists in wordList
        bool endFound = false;
        for (auto &w : wordList) {
            if (w == endWord) {
                endFound = true;
                break;
            }
        }
        if (!endFound) return {};

        // 2. Ensure beginWord is uniquely placed at the end of wordList (index n - 1)
        vector<string> cleanList;
        for (auto &w : wordList) {
            if (w != beginWord) {
                cleanList.push_back(w);
            }
        }
        cleanList.push_back(beginWord);
        wordList = cleanList;

        int n = wordList.size();
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++) {
            um[wordList[i]] = i;
        }

        // 3. BFS to compute shortest distance to every word from beginWord
        vector<int> dis(n, 1e9);
        queue<string> q;

        q.push(beginWord);
        dis[um[beginWord]] = 1;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int step = dis[um[word]];

            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (um.count(temp)) {
                        int j = um[temp];
                        if (dis[j] > step + 1) {
                            dis[j] = step + 1;
                            q.push(temp);
                        }
                    }
                }
            }
        }

        // If endWord is unreachable
        if (dis[um[endWord]] == 1e9)
            return {};

        // 4. Backtrack using DFS from endWord back to beginWord
        vector<vector<vector<string>>> dp(n);
        vector<bool> visited(n, false);

        return dfs(n, um[endWord], dp, wordList, dis, visited, um);
    }
};