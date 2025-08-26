#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> results;
        string current;
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                results.push(current);
                k = 0;
                current.clear();
            } else if (c == ']') {
                string temp = current;
                current = results.top();
                results.pop();
                int repeat = counts.top();
                counts.pop();
                for (int i = 0; i < repeat; i++) {
                    current += temp;
                }
            } else {
                current += c;
            }
        }

        return current;
    }
};

int main() {
    Solution obj;
    string s[] = {"3[a2[c]]", "2[abc]3[cd]ef", "abc"};
    string result = obj.decodeString(s[0]);
    cout << result << endl;
    result = obj.decodeString(s[1]);
    cout << result << endl;
    result = obj.decodeString(s[2]);
    cout << result << endl;
    return 0;
}