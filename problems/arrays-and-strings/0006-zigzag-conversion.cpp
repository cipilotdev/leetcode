#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string result;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.length(); j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.length()) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string testString[] = {
        {"PAYPALISHIRING"},
        {"HELLO"},
        {"ZIGZAGCONVERSION"},
        {"EXTRA"}
    };
    int numRows = 3;
    for (const auto& str : testString) {
        string result = sol.convert(str, numRows);
        cout << "Zigzag conversion of \"" << str << "\" with " << numRows << " rows: " << result << endl;
    }
    return 0;
}