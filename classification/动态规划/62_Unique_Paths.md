## Unique Paths

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

**Example 1:**

```
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Example 3:**

```
Input: m = 7, n = 3
Output: 28
```

**Example 4:**

```
Input: m = 3, n = 3
Output: 6
```

**Constraints:**

- `1 <= m, n <= 100`
- It's guaranteed that the answer will be less than or equal to `2 * 10^9`.

#### 动态规划：

​				保存每个位置可能到达该位置的路径数目。

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0)
                    map[i][j] = 1;
                else{
                    map[i][j] = map[i-1][j] + map[i][j-1];
                }
            }
        }
        return map[m-1][n-1];
    }
};
```

#### 2020.12.9 再回首

#### 组合数学：

​		从左上角到右下角的过程中，需要移动 m + n - 2 次，其中有 m - 1 次向下移动，n - 1 次向右移动。

​		路径总数等于从 m + n - 2 次移动中选择 m - 1 次向下移动的方案数，即组合数：

$$c_{m+n-2}^{m-1} = \tbinom{m+n-2}{m-1} = \frac{(m+n-2)(m+n-3) \cdots n}{(m-1)!} = \frac{(m+n-2)!}{(m-1)!(n-1)!}$$

​		代码可以直接调用现有 API，也可以直接计算。

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for(int x = n, y = 1; y < m; x++,y++)
            ans = ans * x / y;
        return ans;
    }
};
```

