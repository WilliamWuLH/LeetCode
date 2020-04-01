## LRU Cache

#### map存数据，vector更新优先级：

```c++
class LRUCache {
private:
    map<int, int> store;
    int size = 0;
    vector<int> LRU;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(store.count(key) > 0){
            vector<int>::iterator it = find(LRU.begin(), LRU.end(), key);
            LRU.erase(it);
            LRU.push_back(key);
            return store[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(store.count(key) > 0){
            vector<int>::iterator it = find(LRU.begin(), LRU.end(), key);
            LRU.erase(it);
            LRU.push_back(key);
            store[key] = value;
        }
        else if(size > 0){
            store[key] = value;
            LRU.push_back(key);
            size--;
        }
        else{
            int tkey = *(LRU.begin());
            store.erase(tkey);
            LRU.erase(LRU.begin());
            store[key] = value;
            LRU.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

