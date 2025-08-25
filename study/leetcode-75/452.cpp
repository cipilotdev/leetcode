#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end = points[0][1];

        for (const auto& point : points) {
            if (point[0] > end) {
                arrows++;
                end = point[1];
            }
        }

        return arrows;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int result = sol.findMinArrowShots(points);
    cout << "Minimum number of arrows required: " << result << endl;
    return 0;
}