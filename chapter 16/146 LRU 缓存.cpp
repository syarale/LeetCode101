
// 146. LRU Cache 

class LRUCache {
private:
    list<pair<int, int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> hash;
    int maxSize;
public:
    LRUCache(int capacity) : maxSize(capacity) {

    }
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return (*(it->second)).second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            (*(it->second)).second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        cache.insert(cache.begin(), make_pair(key, value));
        hash[key] = cache.begin();

        if (cache.size() > maxSize) {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
