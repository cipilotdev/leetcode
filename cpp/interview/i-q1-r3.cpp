#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
            }
        }
        return i == n - 1;
    }
};

int main() {
    Solution obj;
    vector<int> bits = {1, 0, 0};
    bool ans = obj.isOneBitCharacter(bits);
    return ans;
}
