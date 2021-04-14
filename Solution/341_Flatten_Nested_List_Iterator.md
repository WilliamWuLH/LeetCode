## Flatten Nested List Iterator

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

- `NestedIterator(List nestedList)` Initializes the iterator with the nested list `nestedList`.
- `int next()` Returns the next integer in the nested list.
- `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

**Example 1:**

```
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

**Example 2:**

```
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

**Constraints:**

- `1 <= nestedList.length <= 500`
- The values of the integers in the nested list is in the range `[-10^6, 10^6]`.

#### 栈：

```c++
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        // 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto &p = stk.top();
            if (p.first == p.second) { // 遍历到当前列表末尾，出栈
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
            auto &lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```

