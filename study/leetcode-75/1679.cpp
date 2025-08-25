#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int operations = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (freq[nums[i]] > 0 && freq[k - nums[i]] > 0) {
                operations += min(freq[nums[i]], freq[k - nums[i]]);
            }
        }

        return operations;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    int result = sol.maxOperations(nums, k);
    cout << result << endl;
    return 0;
}