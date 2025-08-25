#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        
        while (!r.empty() && !d.empty()) {
            int ri = r.front(); r.pop();
            int di = d.front(); d.pop();
            if (ri < di) {
                r.push(ri + n);
            } else {
                d.push(di + n);
            }
        }
        
        return r.empty() ? "Dire" : "Radiant";
    }
};


int main() {
    Solution sol;
    cout << sol.predictPartyVictory("RDD") << endl;  // Output: "Dire"
    cout << sol.predictPartyVictory("RRR") << endl;  // Output: "Radiant"
    cout << sol.predictPartyVictory("DRR") << endl;  // Output: "Radiant"
    cout << sol.predictPartyVictory("DDRRR") << endl; // Output: "Dire"
    cout << sol.predictPartyVictory("RDDR") << endl;  // Output: "Radiant"
    return 0;
}