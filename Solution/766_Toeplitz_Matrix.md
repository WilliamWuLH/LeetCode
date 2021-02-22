## Toeplitz Matrix

Given an `m x n` `matrix`, return *`true` if the matrix is Toeplitz. Otherwise, return `false`.*

A matrix is **Toeplitz** if every diagonal from top-left to bottom-right has the same elements.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg)

```
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg)

```
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 20`
- `0 <= matrix[i][j] <= 99`

**Follow up:**

- What if the `matrix` is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
- What if the `matrix` is so large that you can only load up a partial row into the memory at once?

#### 遍历：

​		遍历矩阵中的元素，判断该元素和它的左上方的元素是否相同，也就是在同一条对角线上的前一个元素是否相同。如果不相同可以直接返回 false。遍历完整个数组并且没有提前返回 false，则说明该矩阵是托普利茨矩阵，返回 true。

```c++
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};
```

