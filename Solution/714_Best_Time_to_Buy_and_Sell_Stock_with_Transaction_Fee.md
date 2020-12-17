## Best Time to Buy and Sell Stock with Transaction Fee

Your are given an array of integers `prices`, for which the `i`-th element is the price of a given stock on day `i`; and a non-negative integer `fee` representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

**Example 1:**

```
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Note:**

- `0 < prices.length <= 50000`.
- `0 < prices[i] < 50000`.
- `0 <= fee < 50000`.

#### 贪心：

​		将手续费放在买入时进行计算，可以得到一种基于贪心的方法。

​		buy 表示在最大化收益的前提下，如果我们手上拥有一支股票，那么它的最低买入价格是多少。

​		在初始时，buy 的值为 prices[0] 加上手续费 fee。那么当我们遍历到第 i ( i > 0 ) 天时：

1. 如果当前的股票价格 prices[i] 加上手续费 fee 小于 buy，那么与其使用 buy 的价格购买股票，我们不如以 prices[i] + fee 的价格购买股票，因此我们将 buy 更新为 prices[i]+fee。
2. 如果当前的股票价格 prices[i] 大于 buy，那么我们直接卖出股票并且获得 prices[i]−buy 的收益。但实际上，我们此时卖出股票可能并不是全局最优的（例如下一天股票价格继续上升），因此我们可以提供一个反悔操作，看成当前手上拥有一支买入价格为 prices[i] 的股票，将 buy 更新为 prices[i]。这样一来，如果下一天股票价格继续上升，我们会获得 prices[i+1] − prices[i] 的收益，加上这一天 prices[i] − buy 的收益，恰好就等于在这一天不进行任何操作，而在下一天卖出股票的收益。
3. 对于其余的情况，prices[i] 落在区间 \[ buy − fee , buy \] 内，它的价格没有低到我们放弃手上的股票去选择它，也没有高到我们可以通过卖出获得收益，因此我们不进行任何操作。

**当我们卖出一支股票时，我们就立即获得了以相同价格并且免除手续费买入一支股票的权利。**

参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int buy = prices[0]+fee;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(prices[i] < buy-fee)
                buy = prices[i]+fee;
            else if(prices[i] > buy){
                ans += prices[i]-buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};
```

