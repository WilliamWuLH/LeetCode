## Spiral Matrix II

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n2` in spiral order.

**Example 1:**

```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

**Example 2:**

```
Input: n = 1
Output: [[1]]
```

**Constraints:**

- `1 <= n <= 20`

#### 层次遍历 + 边界/方向判断：

​		螺旋矩阵，就是分类讨论，确定边界 + 方向就很简单。

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int count = 1;
        int level = 0;
        while(1){
            for(int i=level; i<n-level; i++)
                ans[level][i] = count++;
            if(count > n*n)    break;
            for(int i=level+1; i<n-level; i++)
                ans[i][n-level-1] = count++;
            if(count > n*n)    break;
            for(int i=n-level-2; i>=level; i--)
                ans[n-level-1][i] = count++;
            if(count > n*n)    break;
            for(int i=n-level-2; i>level; i--)
                ans[i][level] = count++;
            if(count > n*n)    break;
            level++;
        }
        return ans;
    }
};
```

