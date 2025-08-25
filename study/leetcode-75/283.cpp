#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZero], nums[i]);
                lastNonZero++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}