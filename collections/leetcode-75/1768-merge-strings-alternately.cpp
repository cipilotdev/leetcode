#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            merged += word1[i++];
            merged += word2[j++];
        }
        merged += word1.substr(i);
        merged += word2.substr(j);
        return merged;
    }
};

int main() {
    Solution sol;
    string word1 = "abc";
    string word2 = "pqr";
    string result = sol.mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;
    return 0;
}