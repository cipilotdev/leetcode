#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        for (int d = 0; d < m + n - 1; ++d) {
            int r = d < n ? 0 : d - n + 1;
            int c = d < n ? d : n - 1;
            while (r < m && c >= 0) {
                result.push_back(mat[r][c]);
                ++r;
                --c;
            }

            if (d % 2 == 0) {
                int start = result.size() - (min(d, m - 1) - max(0, d - n + 1) + 1);
                int end = result.size() - 1;
                while (start < end) {
                    swap(result[start++], result[end--]);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = sol.findDiagonalOrder(mat);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}