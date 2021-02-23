## Grumpy Bookstore Owner

Today, the bookstore owner has a store open for `customers.length` minutes. Every minute, some number of customers (`customers[i]`) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. If the bookstore owner is grumpy on the i-th minute, `grumpy[i] = 1`, otherwise `grumpy[i] = 0`. When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for `X` minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

**Example 1:**

```
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
```

**Note:**

- `1 <= X <= customers.length == grumpy.length <= 20000`
- `0 <= customers[i] <= 1000`
- `0 <= grumpy[i] <= 1`

#### 滑动窗口：

​		根据题意可知，本题中滑动窗口的窗口大小是固定的，因为书店老板可以让自己连续 X 分钟不生气，但却只能使用一次，所以我们的窗口大小始终是 X，并且只有这么一个窗口。

​		因此，我们可以遍历 customers 数组，判断并统计当书店老板不生气时的顾客数量，即当 grumpy[i] == 0 时 customers[i] 的大小，此时的客户都是能够感到满意的。然后在我们进行遍历的同时也可以进行滑动窗口的滑动，判断窗口中当书店老板由生气变成不生气时顾客能够增加的数目，并且不断更新最大的增加数目。

​		最后的答案就是书店老板不生气时的顾客总和加上滑动窗口中书店老板由生气变为不生气所增加的顾客数目的最大值之和。

```c++
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0, more = 0, ans = 0, n = customers.size();
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0)
                sum += customers[i];
            else
                more += customers[i];
            if(i >= X - 1){
                ans = max(ans, more);
                if(grumpy[i-X+1] == 1)
                    more -= customers[i-X+1];
            }
        }
        return sum + ans;
    }
};
```

