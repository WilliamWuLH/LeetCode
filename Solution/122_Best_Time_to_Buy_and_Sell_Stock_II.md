## Best Time to Buy and Sell Stock II

Say you have an array `prices` for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

**Note:** You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
```

**Example 2:**

```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

**Constraints:**

- `1 <= prices.length <= 3 * 10 ^ 4`
- `0 <= prices[i] <= 10 ^ 4`

#### 判断上升下降的趋势：

​		当前还未买入：如果下一次的价格比这一次高，则这一次要买入，否则不操作。

​		当前已经买入：如果下一次的价格比这一次低，则这一次要卖出，否则不操作。

重点难点：最后的价格需要单独讨论。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, begin = -1;
        for(int i=0; i<prices.size()-1; i++){
            if(begin < 0){
                if(prices[i] < prices[i+1])
                    begin = i;
                continue;
            }
            else{
                if(prices[i] > prices[i+1]){
                    sum += prices[i] - prices[begin];
                    begin = -1;
                }
                continue;
            }
        }
        if(begin > -1)
            sum += prices[prices.size()-1] - prices[begin];
        return sum;
    }
};
```

