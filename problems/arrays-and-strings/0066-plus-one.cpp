#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> testCases[] = {
        {1, 2, 3},
        {4, 3, 2, 1},
        {9},
        {9, 9, 9},
        {0},
        {1, 9, 9},
        {2, 9, 9},
        {9, 8, 9},
        {1, 2, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
    };

    for (auto& digits : testCases) {
        vector<int> result = sol.plusOne(digits);
        cout << "Result: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}