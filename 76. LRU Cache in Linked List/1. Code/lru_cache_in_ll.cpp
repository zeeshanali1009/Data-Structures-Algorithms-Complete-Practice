#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Helper to add node right after head (most recently used)
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper to remove node from linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the head (most recently used)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Pop least recently used node (from tail->prev)
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // not found
        }
        Node* node = mp[key];
        moveToHead(node); // update recent use
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists -> update value and move to head
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            // New key -> create node
            Node* node = new Node(key, value);
            mp[key] = node;
            addNode(node);

            if ((int)mp.size() > capacity) {
                Node* lru = popTail();
                mp.erase(lru->key);
                delete lru;
            }
        }
    }
};

// Example usage
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // -1
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}
