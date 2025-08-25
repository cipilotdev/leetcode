#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int end = INT_MIN;
        for (const auto& interval : intervals) {
            if (interval[0] < end) {
                count++;
            } else {
                end = interval[1];
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Number of intervals to remove: " << result << endl;
    return 0;
}