## Minimize Deviation in Array

You are given an array `nums` of `n` positive integers.

You can perform two types of operations on any element of the array any number of times:

- If the element is even, divide it by 2.
  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the last element, and the array will be `[1,2,3,2].`
- If the element is odd, multiply it by 2.
  - For example, if the array is `[1,2,3,4]`, then you can do this operation on the first element, and the array will be `[2,2,3,4].`

The **deviation** of the array is the **maximum difference** between any two elements in the array.

Return *the **minimum deviation** the array can have after performing some number of operations.*

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
```

**Example 2:**

```
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
```

**Example 3:**

```
Input: nums = [2,10,8]
Output: 3
```

**Constraints:**

- `n == nums.length`
- `2 <= n <= 10^5`
- `1 <= nums[i] <= 10^9`

#### 贪心 + 优先队列 + 循环处理：

​		可以考虑把所有数都化为最大的形式(全部化为所能变成的最大偶数)，然后加入大根堆，维护 min1 表示当前堆的最小值，堆顶即为最大值。

​		为了不断缩小最大值与最小值的差，我们必须不断取出当前堆最大的数，然后将其除以 2，重新加入队列。

​		这个过程同时维护答案 ans 和 min1，则有 min1 = min(min1, cur)，ans = min(ans, q.top() - min1)。

​		当堆顶为奇数时，意味着不能再除以 2，最大值不可能再改变，差距也就不会再被缩小，此时的 ans 即为答案。

**参考：[Benboby](https://leetcode-cn.com/u/benboby/)**

```c++
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int min1 = INT_MAX;
        for(auto &i : nums){
            if(i % 2)
                i <<= 1;
            q.push(i);
            min1 = min(min1, i);
        }
        int ans = q.top() - min1;
        while(q.top() % 2 == 0){
            int cur = q.top() >> 1;
            q.pop();
            q.push(cur);
            min1 = min(min1, cur);
            ans = min(ans, q.top() - min1);
        }
        return ans;
    }
};
```

