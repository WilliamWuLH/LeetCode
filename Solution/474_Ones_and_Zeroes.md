## Ones and Zeroes

You are given an array of binary strings `strs` and two integers `m` and `n`.

Return *the size of the largest subset of `strs` such that there are **at most*** `m` `0`*'s and* `n` `1`*'s in the subset*.

A set `x` is a **subset** of a set `y` if all elements of `x` are also elements of `y`.

**Example 1:**

```
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
```

**Example 2:**

```
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
```

**Constraints:**

- `1 <= strs.length <= 600`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists only of digits `'0'` and `'1'`.
- `1 <= m, n <= 100`

#### 动态规划：0-1 背包问题

​		这题十分类似动态规划中很经典的一个问题：0-1 背包问题。

​		提取本题的关键信息：

- 限制条件：最终的子集（也就是背包中的物品）最多有 m 个 0 和 n 个 1 。
- 最终目标：返回 strs 的最大子集的大小，也就是在背包中可以装入的最多物品数目。

​		本题和 0-1 背包问题的不同点：

- 0-1 背包问题中物品能否装入背包的条件只有一个：物品的重量和背包的剩余可装入重量。而本题需要考虑两个维度，即字符串中 0 的个数和子集剩余可用的 0 的个数以及字符串中 1 的个数和子集剩余可用的 1 的个数。
- 0-1 背包问题的最终目标是使背包中物品的总价值最大，也就是说每个物品的价值不同。而本题的最终目标是子集中使得字符串最多的情况，即每个字符串的“价值”都是 1，求最后子集的总价值最大。



通过以上分析，可以写出状态转移方程：（此时字符串中含有 zeros 个 0 和 ones 个 1）

$dp_{i,j}=\left\{ \begin{array}{lr} \max(dp_{i,j},\  dp_{i-zeros, j-ones}+1),  & zeros\leq i\leq m, ones\leq i\leq n \\ dp_{i, j} & 0 \leq i < zeros, 0 \leq j < ones\end{array}  \right.$



注意由于每个字符串只能使用一次（即有限背包），因此在更新 dp(i, j) 时，i 和 j 都需要从大到小进行枚举。

最终的答案即为所有 dp(i, j) 中的最大值。

代码如下：

```c++
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto &s : strs){
            int ones = 0, zeros = 0;
            for(auto &i : s)
                if(i == '0')
                    zeros++;
            ones = s.length()-zeros;
            for(int i=m; i>=zeros; i--)
                for(int j=n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }
        return dp[m][n];
    }
};
```

