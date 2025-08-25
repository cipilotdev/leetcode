#include <vector>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = solution.pivotIndex(nums);
    cout << "Pivot index: " << result << endl;
    return 0;
}