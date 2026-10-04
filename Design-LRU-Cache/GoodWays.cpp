#include <iostream>
#include <unordered_map>

using namespace std;

class Node {

public:

    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }

};


class DoublyLinkedList {
public:

    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node* push_front(int key, int value) {

        Node* newNode = new Node(key, value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return newNode;
        }
        
        newNode->next = head;
        head->prev = newNode;

        head  = newNode;

        return newNode;
    }

    // we have alredy node only remove node O(1) no need to searching
    void erase(Node* node) {

        if (node == nullptr) {
            return;
        }

        // check not is head node
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            // this is head node
            head = node->next;
        }

        // check not is tail node
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }

        delete node;
    }

    void pop_back() {
        
        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;

        //if only one node
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
    }
    
    // remove on the back and function need to return a key because we have to remove on a cache
    int back() {

        if (tail == nullptr) {
            return -1;
        }

        return tail->key;
    }
};

class LRUCache {
public:

    DoublyLinkedList dll;
    // store key -> node
    unordered_map<int, Node*> map;
    int n ;

    LRUCache(int capacity) {

        this->n = capacity;
    }

    // helper function follow the property LRU
    void makeMostRecentNode(int key, int value) {

        Node* oldNode = map[key];

        dll.erase(oldNode);

        Node* newNode = dll.push_front(key, value);

        map[key] = newNode;

    }

    int get(int key) {

        if (!map.count(key)) {
            return -1;
        }

        Node* node = map[key];
        int value = node->value;

        makeMostRecentNode(key, value);

        return value;

    }

    void put(int key, int value) {

        if (map.count(key)) {
            // if already exist update the value and put on front
            makeMostRecentNode(key, value);
        } else {
            // create a new node and push on front
            Node* newNode = dll.push_front(key, value);
            map[key] = newNode;
            n--;
        }

        // if any time my size will full

        if (n < 0) {

            int leastRecentUse = dll.back();

            map.erase(leastRecentUse);
            dll.pop_back();

            n++;
        }

        return;
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

    
    return 0;
}