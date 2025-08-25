#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i] == getColumn(grid, j)) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    vector<int> getColumn(const vector<vector<int>>& grid, int col) {
        vector<int> column;
        for (const auto& row : grid) {
            column.push_back(row[col]);
        }
        return column;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {1, 2, 3}
    };
    int result = solution.equalPairs(grid);
    cout << "Number of equal pairs: " << result << endl;
    return 0;
}
