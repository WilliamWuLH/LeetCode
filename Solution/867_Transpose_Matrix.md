## Transpose Matrix

Given a 2D integer array `matrix`, return *the **transpose** of* `matrix`.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

![img](https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png)

**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
```

**Example 2:**

```
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 1000`
- `1 <= m * n <= 10^5`
- `-10^9 <= matrix[i][j] <= 10^9`

#### 遍历：

​		原矩阵 matrix 的行数为 r，列数为 c，则它的转置矩阵的行数为 c，列数为 r。

​		直接遍历原矩阵 matrix，把 matrix\[i\]\[j\] 的数复制到 ans\[j\]\[i\]，最后返回 ans。

```c++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> ans(c, vector<int>(r, 0));
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                ans[j][i] = matrix[i][j];
        return ans;
    }
};
```

