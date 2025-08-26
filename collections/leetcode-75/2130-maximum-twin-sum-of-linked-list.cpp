#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        int maxSum = 0;
        int n = values.size();
        for (int i = 0; i < n / 2; ++i) {
            maxSum = max(maxSum, values[i] + values[n - 1 - i]);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(5);
    ListNode* second = new ListNode(4);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(2);
    ListNode* fifth = new ListNode(1);
}