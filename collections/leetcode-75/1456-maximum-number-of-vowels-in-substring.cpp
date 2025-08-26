#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0;
        int currentCount = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < s.size(); i++) {
            if (vowels.count(s[i])) {
                currentCount++;
            }
            if (i >= k && vowels.count(s[i - k])) {
                currentCount--;
            }
            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};

int main() {
    Solution solution;
    string s = "abciiidef";
    int k = 3;
    int result = solution.maxVowels(s, k);
    cout << "Max vowels in substring of length " << k << ": " << result << endl;
    return 0;
}