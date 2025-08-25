#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;

        int write = 0;
        int count = 1;

        for (int read = 1; read < n; read++) {
            if (chars[read] == chars[read - 1]) {
                count++;
            } else {
                chars[write++] = chars[read - 1];
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[write++] = c;
                    }
                }
                count = 1;
            }
        }

        chars[write++] = chars[n - 1];
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }

        return write;
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = sol.compress(chars);
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;
    return 0;
}