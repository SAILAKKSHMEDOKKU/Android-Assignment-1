#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 1009; 
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:

    MyHashMap() {
        table.resize(SIZE);
    }


    void put(int key, int value) {
        int h = hash(key);
        for (auto& pair : table[h]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[h].push_back({key, value});
    }


    int get(int key) {
        int h = hash(key);
        for (auto& pair : table[h]) {
            if (pair.first == key)
                return pair.second;
        }
        return -1;
    }


    void remove(int key) {
        int h = hash(key);
        auto& bucket = table[h];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};


int main() {
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl;  
    cout << obj.get(3) << endl;  
    obj.put(2, 30);              
    cout << obj.get(2) << endl;  
    obj.remove(2);               
    cout << obj.get(2) << endl;  
    return 0;
}
