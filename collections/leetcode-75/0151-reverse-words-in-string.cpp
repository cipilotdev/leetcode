#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;
        while (j >= i && s[j] == ' ') j--;
        s = s.substr(i, j - i + 1);

        string temp;
        bool space = false;
        for (char c : s) {
            if (c == ' ') {
                if (!space) temp += ' ';
                space = true;
            } else {
                temp += c;
                space = false;
            }
        }
        s = temp;

        reverse(s.begin(), s.end());

        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "   the sky is blues    ";
    string result = sol.reverseWords(s);
    cout << result << endl;  // Output: "blues is sky the"
    return 0;
}
