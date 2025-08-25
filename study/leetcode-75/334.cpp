#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    bool result = sol.increasingTriplet(nums);
    cout << (result ? "True" : "False") << endl;
    return 0;
}