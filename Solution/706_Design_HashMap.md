## Design HashMap

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

- `put(key, value)` : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
- `get(key)`: Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
- `remove(key)` : Remove the mapping for the value key if this map contains the mapping for the key.


**Example:**

```
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 
```


**Note:**

- All keys and values will be in the range of `[0, 1000000]`.
- The number of operations will be in the range of `[1, 10000]`.
- Please do not use the built-in HashMap library.

#### 设计哈希映射：

​		有两种实现方法：开散列法和闭散列法

参考：[哈希表](https://oi-wiki.org/ds/hash/)

实现：[ **HashTable** ](https://github.com/WilliamWuLH/LeetCode/tree/master/Algorithm/HashTable)

```c++
class MyHashMap {
private:
    const int N = 360007;
    vector<int> keys;
    vector<int> values;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keys.assign(N, -1);
        values.assign(N, -1);
    }

    int getIndex(int key) {
        int index = (key % N + N) % N, cnt = 1;
        while(keys[index] != key && values[index] != -1){
            index = (index + cnt * cnt) % N;
            cnt++;
        }
        return index;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = getIndex(key);
        keys[index] = key;
        values[index] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = getIndex(key);
        return values[index];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = getIndex(key);
        keys[index] = -1;
        values[index] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```

