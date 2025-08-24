#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int testNumbers[] = { 121, -121, 10, 123, 1234567899 };
    for (int i = 0; i < 5; i++) {
    
    if (sol.isPalindrome(testNumbers[i])) {
            cout << testNumbers[i] << " is a palindrome." << endl;
        } else {
            cout << testNumbers[i] << " is not a palindrome." << endl;
        }
    }
    return 0;
}