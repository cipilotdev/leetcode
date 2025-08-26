#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution sol;
    string str1 = "ABCABC";
    string str2 = "ABC";
    string result = sol.gcdOfStrings(str1, str2);
    cout << "GCD of strings: " << result << endl;
    return 0;
}