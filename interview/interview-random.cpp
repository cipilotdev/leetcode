#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionDeleteNode {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return;
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};

class SolutionHammingWeight {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // drop lowest set bit
            count++;
        }
        return count;
    }
};

class SolutionNimGame {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

class SolutionHammingDistance {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    cout << "=== Testing Delete Node ===" << endl;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    SolutionDeleteNode solDel;
    solDel.deleteNode(head->next);
    cout << "After deleting node with val=2: ";
    printList(head);

    solDel.deleteNode(head);
    cout << "After deleting head node: ";
    printList(head);

    // Cleanup list
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    cout << "\n=== Testing Hamming Weight ===" << endl;
    SolutionHammingWeight solHW;
    vector<int> hwTests = {0, 1, 3, 7, 11, 1023, -1};
    for (int n : hwTests) {
        cout << "n=" << n << " -> hammingWeight=" << solHW.hammingWeight(n) << endl;
    }

    cout << "\n=== Testing Nim Game ===" << endl;
    SolutionNimGame solNim;
    for (int n = 1; n <= 12; n++) {
        cout << "n=" << n << " -> canWin=" << (solNim.canWinNim(n) ? "true" : "false") << endl;
    }

    cout << "\n=== Testing Hamming Distance ===" << endl;
    SolutionHammingDistance solHD;
    vector<pair<int,int>> hdTests = {
        {1, 4},
        {3, 1},
        {7, 0},
        {15, 8},
        {31, 14}
    };
    for (auto [x, y] : hdTests) {
        cout << "x=" << x << ", y=" << y << " -> hammingDistance=" 
             << solHD.hammingDistance(x, y) << endl;
    }

    return 0;
}
