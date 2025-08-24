#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2) return points.size();

        int maxPoints = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> slopeCount;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    double slope = (points[j][0] - points[i][0] == 0) ?
                                   numeric_limits<double>::infinity() :
                                   static_cast<double>(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    slopeCount[slope]++;
                }
            }
            int currentMax = 0;
            for (const auto& entry : slopeCount) {
                currentMax = max(currentMax, entry.second);
            }
            maxPoints = max(maxPoints, currentMax + 1);
        }
        return maxPoints;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 1}, {5, 5}};
    cout << sol.maxPoints(points) << endl;
    return 0;
}