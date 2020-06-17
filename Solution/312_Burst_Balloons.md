## Burst Balloons

#### 动态规划：

​		找对状态转移方程太重要了，还有就是对数组的处理以及边界情况的判断。

​		此题类似于矩阵连乘的问题，但是比它复杂一些，需要考虑相邻的数改变的问题。

```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0)
            return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[len+2][len+2];
        for(int l=1; l<=len+1; l++){
            for(int pos=0; pos<=len+1-l; pos++){
                int tmax = 0;
                for(int k=pos+1; k<pos+l; k++){
                    tmax = max(tmax, dp[pos][k] + dp[k][pos+l] + nums[pos]*nums[k]*nums[pos+l]);
                }
                dp[pos][pos+l] = tmax;
            }
        }
        return dp[0][len+1];
    }
};
```

