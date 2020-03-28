## Best Time to Buy and Sell Stock

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

