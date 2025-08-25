#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (vowels.find(s[left]) != string::npos && vowels.find(s[right]) != string::npos) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            if (vowels.find(s[left]) == string::npos) left++;
            if (vowels.find(s[right]) == string::npos) right--;
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "hello";
    string result = sol.reverseVowels(s);
    cout << result << endl;
    return 0;
}