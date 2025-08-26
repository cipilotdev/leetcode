#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "leet**cod*e";
    string result = solution.removeStars(s);
    cout << "Result after removing stars: " << result << endl;
    return 0;
}