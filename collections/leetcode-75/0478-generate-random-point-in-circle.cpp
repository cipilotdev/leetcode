#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x, y;
        do {
            x = ((double) rand() / RAND_MAX) * 2 * radius - radius + x_center;
            y = ((double) rand() / RAND_MAX) * 2 * radius - radius + y_center;
        } while (pow(x - x_center, 2) + pow(y - y_center, 2) > pow(radius, 2));
        return {x, y};
    }

private:
    double radius;
    double x_center;
    double y_center;
};

int main() {
    Solution* obj = new Solution(1.0, 0.0, 0.0);
    vector<double> param_1 = obj->randPoint();
    return 0;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */