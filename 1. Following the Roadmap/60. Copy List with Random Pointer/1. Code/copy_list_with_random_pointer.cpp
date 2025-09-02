#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;  // map old node -> new node

        // Step 1: Copy all nodes (only val, next = NULL, random = NULL for now)
        Node* oldp = head;
        while (oldp != NULL) {
            Node* copyNode = new Node(oldp->val);
            mp[oldp] = copyNode;  // store mapping
            oldp = oldp->next;
        }

        // Step 2: Connect next and random pointers
        oldp = head;
        while (oldp != NULL) {
            mp[oldp]->next = mp[oldp->next];         // connect next
            mp[oldp]->random = mp[oldp->random];     // connect random
            oldp = oldp->next;
        }

        return mp[head];  // return new head
    }
};

// Helper function to print list (val + random’s val)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node(" << temp->val << ")";
        if (temp->random != NULL)
            cout << " -> Random(" << temp->random->val << ")";
        else
            cout << " -> Random(NULL)";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Create example list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Random connections
    head->random = head->next->next;  // 1->random = 3
    head->next->random = head;        // 2->random = 1
    head->next->next->random = head->next;  // 3->random = 2

    cout << "Original List:" << endl;
    printList(head);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedHead);

    return 0;
}
