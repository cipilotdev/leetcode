#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Change it to O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, zeroCount = 0, maxLength = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) zeroCount++;

            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            maxLength = max(maxLength, right - left);
            right++;
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = sol.longestSubarray(nums);
    cout << "Final Answer: " << result << endl;
    return 0;
}
