## Maximum Frequency Stack

Implement `FreqStack`, a class which simulates the operation of a stack-like data structure.

`FreqStack` has two functions:

- `push(int x)`, which pushes an integer `x` onto the stack.
- `pop()`, which removes and returns the most frequent element in the stack.
  - If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

**Example 1:**

```
Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
```

**Note:**

- Calls to `FreqStack.push(int x)` will be such that `0 <= x <= 10^9`.
- It is guaranteed that `FreqStack.pop()` won't be called if the stack has zero elements.
- The total number of `FreqStack.push` calls will not exceed `10000` in a single test case.
- The total number of `FreqStack.pop` calls will not exceed `10000` in a single test case.
- The total number of `FreqStack.push` and `FreqStack.pop` calls will not exceed `150000` across all test cases.

#### 哈希表 + 栈：

**思路**

​		显然，我们更关心元素的频率。令 freq 作为 x 到 x 的出现次数的映射 Map。

​		此外，我们也（可能）关心 maxfreq，即栈中任意元素的当前最大频率。这是理所应当的事情，因为我们必须弹出频率最高的元素。

​		那么当前主要的问题就变成了：在具有相同的（最大）频率的元素中，怎么判断那个元素是最新的？我们可以使用栈来查询这一信息：靠近栈顶的元素总是相对更新一些。

​		为此，我们令 group 作为从频率到具有该频率的元素的映射。到目前，我们已经实现了 FreqStack 的所有必要的组件。

**算法**

​		实际上，作为实现层面上的一点细节，如果 x 的频率为 f，那么我们将获取在所有 group[i] (i <= f) 中的 x，而不仅仅是栈顶的那个。这是因为每个 group[i] 都会存储与第 i 个 x 副本相关的信息。

​		此后，我们仅仅需要如上所述维护 freq，group，以及 maxfreq。

**参考：[力扣 (LeetCode)](https://leetcode-cn.com/problems/maximum-frequency-stack/solution/zui-da-pin-lu-zhan-by-leetcode/)**

```c++
class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxfreq = 0;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        maxfreq = max(maxfreq, freq[x]);
        group[freq[x]].push(x);
    }
    
    int pop() {
        int x = group[maxfreq].top();
        group[maxfreq].pop();
        freq[x]--;
        if(group[maxfreq].empty() == true)
            maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
```

