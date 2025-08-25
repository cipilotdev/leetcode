#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }

        unordered_set<int> freqSet;
        for (const auto& pair : countMap) {
            if (!freqSet.insert(pair.second).second) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    bool result = solution.uniqueOccurrences(arr);
    cout << (result ? "true" : "false") << endl;
    return 0;
}