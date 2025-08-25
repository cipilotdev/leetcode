#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = *max_element(candies.begin(), candies.end());
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);
    for (bool canHaveMost : result) {
        cout << (canHaveMost ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}