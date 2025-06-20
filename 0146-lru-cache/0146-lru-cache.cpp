class LRUCache {
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> lookup;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto itr = lookup.find(key);
        if(itr == lookup.end(key)){
            return -1;
        }

        int value = itr->second->second;
        lru.erase(itr->second);
        lru.push_front({key, value});

        lookup.erase(itr);
        lookup[key] = lru.begin();

        return value;
        
    }
    
    void put(int key, int value) {
        auto itr = lookup.find(key);
        if(itr != lookup.end(key)){
            lru.erase(itr->second);
            lookup.erase(itr);
        }

        lru.push_front({key, value});
        lookup[key] = lru.begin();

        if(lookup.size() > capacity){
            auto it = lookup.find(lru.rbegin()->first);
            lookup.erase(it);
            lru.pop_back();
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */