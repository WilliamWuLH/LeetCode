## LRU Cache

Design a data structure that follows the constraints of a **[Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)**.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.

**Follow up:**
Could you do `get` and `put` in `O(1)` time complexity?

**Example 1:**

```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

**Constraints:**

- `1 <= capacity <= 3000`
- `0 <= key <= 3000`
- `0 <= value <= 10^4`
- At most `3 * 10^4` calls will be made to `get` and `put`.

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

