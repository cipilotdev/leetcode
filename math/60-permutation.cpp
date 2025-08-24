#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }
        for (int i = 0; i < k - 1; i++) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(3, 3) << endl;
    cout << sol.getPermutation(4, 9) << endl;
    cout << sol.getPermutation(3, 1) << endl;
    return 0;
}