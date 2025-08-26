#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int j = 0;

        for (int i = 0; i < n && j < m; i++) {
            if (t[i] == s[j]) {
                j++;
            }
        }

        return j == m;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    bool result = sol.isSubsequence(s, t);
    cout << (result ? "true" : "false") << endl;
    return 0;
}