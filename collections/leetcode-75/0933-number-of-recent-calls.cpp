#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        timestamps = vector<int>();
    }
    
    int ping(int t) {
        timestamps.push_back(t);
        while (timestamps.front() < t - 3000) {
            timestamps.erase(timestamps.begin());
        }
        return timestamps.size();
    }

private:
    vector<int> timestamps;
};

int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;    // Output: 1
    cout << obj->ping(100) << endl;  // Output: 2
    cout << obj->ping(3001) << endl; // Output: 3
    cout << obj->ping(3002) << endl; // Output: 3
    cout << obj->ping(6000) << endl; // Output: 1
    delete obj;
    return 0;
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */