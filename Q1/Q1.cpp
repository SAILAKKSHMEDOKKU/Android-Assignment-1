#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail; 
    
    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            
            if (cache.size() > capacity) {
                Node* tail = popTail();
                cache.erase(tail->key);
                delete tail;
            }
        }
    }
    
    ~LRUCache() {
        Node* curr = head->next;
        while (curr != tail) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        delete tail;
    }
};

int main() {
    LRUCache lru(2);
    
    cout << "Operations:" << endl;
    cout << "lru.put(1, 1)" << endl;
    lru.put(1, 1);
    
    cout << "lru.put(2, 2)" << endl;
    lru.put(2, 2);
    
    cout << "lru.get(1): " << lru.get(1) << endl;
    
    cout << "lru.put(3, 3) (evicts key 2)" << endl;
    lru.put(3, 3);
    
    cout << "lru.get(2): " << lru.get(2) << endl;
    
    cout << "lru.put(4, 4) (evicts key 1)" << endl;
    lru.put(4, 4);
    
    cout << "lru.get(1): " << lru.get(1) << endl;
    cout << "lru.get(3): " << lru.get(3) << endl;
    cout << "lru.get(4): " << lru.get(4) << endl;
    
    return 0;
}
