#include <iostream>
#include <unordered_map>
using namespace std;

// Make it O(1)

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int prevValue = 0;
        for (char c : s) {
            int currValue = 0;
            switch (c) {
                case 'I': currValue = 1; break;
                case 'V': currValue = 5; break;
                case 'X': currValue = 10; break;
                case 'L': currValue = 50; break;
                case 'C': currValue = 100; break;
                case 'D': currValue = 500; break;
                case 'M': currValue = 1000; break;
            }
            if (currValue > prevValue) {
                total += currValue - 2 * prevValue;
            } else {
                total += currValue;
            }
            prevValue = currValue;
        }
        return total;
    }
};

int main() {
    Solution sol;
    string testCases[] = {
        "III", "IV", "IX", "LVIII", "MCMXCIV",
        "XLII", "XCIX", "CDXLIV", "DCCCXC", "MMXXI",
        "I", "II", "V", "X", "L", "C", "D", "M",
        "MMMDCCCLXXXVIII", "MMMCMXCIX", "CDXLIV",
        "MMXX", "MMXXII", "MMXXIII", "MMXXIV",
        "MMXXV", "MMXXVI", "MMXXVII", "MMXXVIII",
        "MMXXIX", "MMXXX", "MMXXXI", "MMXXXII",
        "MMXXXIII", "MMXXXIV", "MMXXXV", "MMXXXVI",
        "MMXXXVII", "MMXXXVIII", "MMXXXIX", "MMXL",
        "MMXLI", "MMXLII", "MMXLIII", "MMXLIV",
        "MMXLV", "MMXLVI", "MMXLVII", "MMXLVIII",
        "MMXLIX", "MML", "MMLI", "MMLII",
    };
    for (const string& test : testCases) {
        cout << "Roman numeral " << test << " is converted to integer " << sol.romanToInt(test) << endl;
    }
    return 0;
}