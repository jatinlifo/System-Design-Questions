#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:

    Node* next;
    Node* prev;
    int key;
    int val;

    Node(int key, int val) {

        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:

    int n;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;


    LRUCache(int capacity) {
        
        this->n = capacity;
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void insertAtTail(Node* node) {

        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;

        return;
    }

    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;


        return;
    }
    
    int get(int key) {
        

        if (!map.count(key)) {
            return -1;
        }

        Node* node = map[key];

        deleteNode(node);
        insertAtTail(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        
        if (map.count(key)) {

            Node* node = map[key];
            deleteNode(node);
            map.erase(key);
        }

        if (map.size() == n) {
            Node* lru = head->next;
            deleteNode(lru);
            map.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        insertAtTail(newNode);

        map[key] = newNode;
    }
};



int main () {

    LRUCache obj(2);

      cout << "========== LRU Cache Test ==========" << endl;

    cout << "\n[1] put(1, 1)" << endl;
    obj.put(1, 1);
    cout << "Inserted key = 1, value = 1" << endl;


    cout << "\n[2] put(2, 2)" << endl;
    obj.put(2, 2);
    cout << "Inserted key = 2, value = 2" << endl;


    cout << "\n[3] get(1)" << endl;
    cout << "Result: " << obj.get(1) << endl;


    cout << "\n[4] get(2)" << endl;
    cout << "Result: " << obj.get(2) << endl;


    cout << "\n[5] put(2, 3)" << endl;
    obj.put(2, 3);
    cout << "Updated key = 2, value = 3" << endl;


    cout << "\n[6] get(2)" << endl;
    cout << "Result: " << obj.get(2) << endl;


    cout << "\n[7] put(3, 3)" << endl;
    obj.put(3, 3);
    cout << "Inserted key = 3, value = 3" << endl;
    cout << "Since capacity = 2, LRU key should be removed." << endl;


    cout << "\n[8] get(3)" << endl;
    cout << "Result: " << obj.get(3) << endl;


    cout << "\n[9] get(1)" << endl;
    cout << "Result: " << obj.get(1) << endl;


    cout << "\n====================================" << endl;
}