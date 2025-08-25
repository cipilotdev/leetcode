#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        bool dp[n][n];
        memset(dp, 0, sizeof(dp));

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution sol;
    string testString[] = {
        {"aba"},
        {"cbbd"},
        {"a"},
        {"ac"},
        {"racecar"}
    };
    for (const auto& str : testString) {
        string result = sol.longestPalindrome(str);
        cout << "Longest palindromic substring of \"" << str << "\": " << result << endl;
    }
    return 0;
}