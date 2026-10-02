#include <iostream>
#include <vector>

using namespace std;

class LRUCache {
public:
    
    vector<pair<int, int>> cache;
    int n;

    LRUCache(int capacity) {
        this->n = capacity;
    }
    
    int get(int key) {
        

        for (int i = 0; i < cache.size(); i++) {

            if (cache[i].first == key) {
                int val = cache[i].second;
                cache.erase(cache.begin() + i);
                cache.push_back({key, val});
                return val;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        for (int i = 0; i < cache.size(); i++) {

            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if (cache.size() == n) {
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
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