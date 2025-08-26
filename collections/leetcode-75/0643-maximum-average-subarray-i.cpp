#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        long long maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        
        return (double)maxSum / k;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double ans = obj.findMaxAverage(nums, 4);
    cout << ans << endl;
    return 0;
}