#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;
            while (!result.empty() && result.back() > 0 && asteroids[i] < 0) {
                if (result.back() < -asteroids[i]) {
                    result.pop_back();
                    continue;
                } else if (result.back() == -asteroids[i]) {
                    result.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                result.push_back(asteroids[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = obj.asteroidCollision(asteroids);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}