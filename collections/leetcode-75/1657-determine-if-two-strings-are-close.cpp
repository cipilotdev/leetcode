#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> count1(26, 0), count2(26, 0);
        for (char c : word1) count1[c - 'a']++;
        for (char c : word2) count2[c - 'a']++;

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};

int main() {
    Solution solution;
    string word1 = "abc";
    string word2 = "bca";
    bool result = solution.closeStrings(word1, word2);
    cout << "Are the strings close? " << (result ? "Yes" : "No") << endl;
    return 0;
}