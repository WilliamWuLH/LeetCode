## Burst Balloons

Given `n` balloons, indexed from `0` to `n-1`. Each balloon is painted with a number on it represented by array `nums`. You are asked to burst all the balloons. If the you burst balloon `i` you will get `nums[left] * nums[i] * nums[right]` coins. Here `left` and `right` are adjacent indices of `i`. After the burst, the `left` and `right` then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

**Note:**

- You may imagine `nums[-1] = nums[n] = 1`. They are not real therefore you can not burst them.
- 0 ≤ `n` ≤ 500, 0 ≤ `nums[i]` ≤ 100

**Example:**

```
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

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

