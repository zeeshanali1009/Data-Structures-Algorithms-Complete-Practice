#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        int count = 0;

        // Step 1: Check if at least k nodes exist
        while (count < k) {
            if (temp == NULL) return head;
            temp = temp->next;
            count++;
        }

        // Step 2: Recursively reverse from k+1 onwards
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: Reverse current k nodes
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
            count++;
        }

        // Step 4: Return new head of this reversed group
        return prevNode;
    }
};

// Utility function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5, k = 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(newHead);

    return 0;
}
