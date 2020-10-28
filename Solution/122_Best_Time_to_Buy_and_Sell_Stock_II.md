## Best Time to Buy and Sell Stock II

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

