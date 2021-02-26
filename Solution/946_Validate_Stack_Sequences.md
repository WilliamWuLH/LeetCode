## Validate Stack Sequences

Given two sequences `pushed` and `popped` **with distinct values**, return `true` if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

**Example 1:**

```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

**Example 2:**

```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

**Constraints:**

- `0 <= pushed.length == popped.length <= 1000`
- `0 <= pushed[i], popped[i] < 1000`
- `pushed` is a permutation of `popped`.
- `pushed` and `popped` have distinct values.

#### 模拟：

​		题目给定 `pushed` 和 `popped` 两个序列，每个序列中的 **值都不重复** 。

​		我们可以模拟栈的 push 和 pop 的过程，首先先判断给定的 pushed 和 popped 的长度是否相同，不相同可以直接返回 false。

​		接下来模拟栈的 push 和 pop 的过程，由于 push 的顺序一定是按照 pushed 的顺序，所以我们可以直接遍历 pushed 数组并且按顺序进行栈的 push 操作。接下来就是判断什么时候进行 pop 操作，当栈不为空的时候，如果此时栈顶元素等于 popped 数组中下一个要 pop 的元素，则此时栈必须进行 pop。在完成栈的 pop 之后判断此时的栈顶是否和 popped 数组中下一个要 pop 的元素相等。

​		最后，pushed 数组中的元素全部按顺序 push 进栈中，所以我们只需要判断 popped 数组中的元素有没有全部按顺序在栈中进行 pop，按照我们上述的操作，就是 popped 数组是不是完全被遍历到，最后返回答案。

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int l = 0;
        if(pushed.size() != popped.size())
            return false;
        for(auto &i : pushed){
            s.push(i);
            while(!s.empty() && s.top() == popped[l]){
                s.pop();
                l++;
            }
        }
        return l == popped.size();
    }
};
```

