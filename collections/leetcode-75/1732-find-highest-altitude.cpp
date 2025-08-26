#include <vector>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};

int main() {
    Solution solution;
    vector<int> gain = {-5, 1, 5, 0, -7};
    int result = solution.largestAltitude(gain);
    cout << "Largest altitude: " << result << endl;
    return 0;
}
