#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        float reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        return reversed;
    }
};

int main() {
    Solution sol;
    int testCases[] = {123, -123, 120, 0};
    for (int x : testCases) {
        int result = sol.reverse(x);
        cout << "Reverse of " << x << " is: " << result << endl;
    }
    return 0;
}