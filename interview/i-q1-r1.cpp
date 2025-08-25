#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = sol.heightChecker(heights);
    cout << "Number of students not in correct height order: " << result << endl;
    return 0;
}