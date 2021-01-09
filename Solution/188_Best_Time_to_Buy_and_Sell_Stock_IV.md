## Best Time to Buy and Sell Stock IV

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Design an algorithm to find the maximum profit. You may complete at most `k` transactions.

**Notice** that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

**Constraints:**

- `0 <= k <= 100`
- `0 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

#### 动态规划：

#### 首先参考 123. Best Time to Buy and Sell Stock III 的解题思路：

[123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

​		由于我们最多可以完成两笔交易，因此在任意一天结束之后，我们会处于以下五个状态中的一种：

- 未进行过任何操作；

- 只进行过一次买操作；

- 进行了一次买操作和一次卖操作，即完成了一笔交易；

- 在完成了一笔交易的前提下，进行了第二次买操作；

- 完成了全部两笔交易。


由于第一个状态的利润显然为 0，所以我们讨论剩下的四种状态，四种状态的最大利润分别设置为：buy1，sell1，buy2 和 sell2。

**状态转移方程**

对于 buy1 而言，在第 i 天我们可以不进行任何操作，保持不变（buy1），也可以在未进行任何操作的前提下以 prices[i] 的价格买入股票（0 - prices[i]）：buy1 = max( buy1, 0 - prices[i] )

对于 sell1 而言，在第 i 天我们可以不进行任何操作，保持不变（sell1），也可以在只进行过一次买操作的前提下以 prices[i] 的价格卖出股票（buy1 + prices[i]）：sell1 = max( sell1, buy1 + prices[i] )

同理，对于 buy2 和 sell2，也有类似的状态转移方程：

- buy2 = max( buy2, sell1 - prices[i] )
- sell2 = max( sell2, buy2 + prices[i] )

**为什么状态转移方程可以这样写？**

​		无论题目中是否允许「在同一天买入并且卖出」这一操作，最终的答案都不会受到影响，这是因为这一操作带来的收益为零。

**边界条件**

​		考虑第 i = 0 天时的四个状态，buy1 即为以 prices[0] 的价格买入股票，因此 buy1 = −prices[0]，sell1 即为在同一天买入并且卖出，因此 sell1 = 0，buy2 即为在同一天买入并且卖出后再以 prices[0] 的价格买入股票，因此 buy2 = −prices[0]，同理可得 sell2 = 0。我们将这四个状态作为边界条件，从 i = 1 开始进行动态规划，即可得到答案。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

#### 本题和 123. Best Time to Buy and Sell Stock III 的区别：

​		本题和 123. Best Time to Buy and Sell Stock III 的区别就是第 123 题最多可以完成两笔交易，而本题最多可以完成 k 笔交易，所以当本题的 k = 2 时其实就是第 123 题。

​		按照上述 123. Best Time to Buy and Sell Stock III 的解题思路，可以推导出当最多可以完成 k 笔交易时应该如何进行动态规划，状态转移方程应该是什么样的，边界条件是什么。

**具体代码如下：**

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 0 || k <= 0)
            return 0;
        vector<vector<int>> buy(n, vector<int>(k, 0));
        vector<vector<int>> sell(n, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            buy[0][i] = -prices[0];
            sell[0][i] = 0;
        }
        for(int i=1; i<n; i++){
            buy[i][0] = max(buy[i-1][0], -prices[i]);
            sell[i][0] = max(sell[i-1][0], buy[i][0] + prices[i]);
            for(int j=1; j<k; j++){
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1] - prices[i]);
                sell[i][j] = max(sell[i-1][j], buy[i][j] + prices[i]);
            }
        }
        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};
```

#### 优化（二维  -->  一维）：

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 0 || k <= 0)
            return 0;
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);
        for(int i=1; i<n; i++){
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j=1; j<k; j++){
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return *max_element(sell.begin(), sell.end());
    }
};
```

