#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for (int i = 0; i < typed.size(); i++) {
            if (j < name.size() && name[j] == typed[i]) {
                j++;
            } else if (i == 0 || typed[i] != typed[i - 1]) {
                return false;
            }
        }
        return j == name.size();
    }
};

int main() {
    Solution sol;
    string name = "alex";
    string typed = "aaleex";
    bool result = sol.isLongPressedName(name, typed);
    cout << "Is long pressed name: " << result << endl;
    return 0;
}