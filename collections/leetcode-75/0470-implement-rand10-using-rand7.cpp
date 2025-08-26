// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    int rand7() {
        return rand() % 7 + 1;
    }
    
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return (idx - 1) % 10 + 1;
    }
};

int main() {
    Solution* obj = new Solution();
    int param_1 = obj->rand10();
    return 0;
}