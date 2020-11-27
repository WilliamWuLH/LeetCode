## Best Time to Buy and Sell Stock

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

**Example 2:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

#### 维持一个最低价 + 一个最优解：

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ans = 0, low = INT_MAX;
        for(int i=0; i<len; i++){
            low = min(low, prices[i]);
            ans = max(ans, prices[i]-low);
        }
        return ans;
    }
};
```

