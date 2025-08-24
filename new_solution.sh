#!/bin/bash

# Script to create a new LeetCode solution template
# Usage: ./new_solution.sh <category> <problem-name> [problem-number]

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_color() {
    echo -e "${1}${2}${NC}"
}

# Function to show usage
show_usage() {
    print_color $BLUE "Usage: $0 <category> <problem-name> [problem-number]"
    echo
    print_color $YELLOW "Categories:"
    echo "  daily     - Daily challenge problems"
    echo "  math      - Math-related problems"
    echo "  random    - Random practice problems"
    echo "  interview - Interview preparation problems"
    echo
    print_color $YELLOW "Examples:"
    echo "  $0 daily two-sum 1"
    echo "  $0 math palindrome-number 9"
    echo "  $0 interview binary-search"
    exit 1
}

# Check arguments
if [ $# -lt 2 ]; then
    show_usage
fi

CATEGORY=$1
PROBLEM_NAME=$2
PROBLEM_NUMBER=${3:-}

# Validate category
case $CATEGORY in
    daily|math|random|interview)
        ;;
    *)
        print_color $RED "Error: Invalid category '$CATEGORY'"
        show_usage
        ;;
esac

# Create filename
if [ -n "$PROBLEM_NUMBER" ]; then
    FILENAME="${PROBLEM_NUMBER}-${PROBLEM_NAME}.cpp"
else
    FILENAME="${PROBLEM_NAME}.cpp"
fi

FILEPATH="${CATEGORY}/${FILENAME}"

# Check if file already exists
if [ -f "$FILEPATH" ]; then
    print_color $RED "Error: File $FILEPATH already exists!"
    exit 1
fi

# Create the C++ template
cat > "$FILEPATH" << EOF
/*
 * Problem: ${PROBLEM_NAME}
 * Category: ${CATEGORY}
 * Difficulty: [Easy/Medium/Hard]
 * 
 * Description:
 * [Add problem description here]
 * 
 * Approach:
 * [Describe your approach here]
 * 
 * Time Complexity: O(?)
 * Space Complexity: O(?)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // TODO: Implement your solution here
    int solutionMethod() {
        return 0;
    }
};

// Test function
void runTests() {
    Solution sol;
    
    // Test case 1
    // TODO: Add test cases
    
    cout << "All tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
EOF

print_color $GREEN "✅ Successfully created: $FILEPATH"
print_color $BLUE "📝 Template includes:"
echo "   - Problem description section"
echo "   - Solution class with placeholder method"
echo "   - Test function template"
echo "   - Common includes"
echo
print_color $YELLOW "Next steps:"
echo "   1. Edit $FILEPATH and implement your solution"
echo "   2. Add test cases to the runTests() function"
echo "   3. Compile with: make $CATEGORY"
echo "   4. Run with: ./${CATEGORY}/output/$(basename "$FILENAME" .cpp)"
