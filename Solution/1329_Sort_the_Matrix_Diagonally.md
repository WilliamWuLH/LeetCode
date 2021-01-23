## Sort the Matrix Diagonally

A **matrix diagonal** is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the **matrix diagonal** starting from `mat[2][0]`, where `mat` is a `6 x 3` matrix, includes cells `mat[2][0]`, `mat[3][1]`, and `mat[4][2]`.

Given an `m x n` matrix `mat` of integers, sort each **matrix diagonal** in ascending order and return *the resulting matrix*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png)

```
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `1 <= mat[i][j] <= 100`

#### 将矩阵按对角线排序：

​		数据范围很小，没有什么难度，直接进行模拟。

​		先遍历矩阵的行，即矩阵中的对角线开始于每一行的第一个元素，开辟一个数组空间，存储以每一行第一个元素开头的对角线的所有元素，对数组进行排序之后再存回原矩阵，即完成矩阵按照对角线进行排序。

​		再遍历矩阵的列，一样的道理，即矩阵中的对角线开始于每一列的第一个元素，开辟一个数组空间，存储以每一列第一个元素开头的对角线的所有元素，对数组进行排序之后再存回原矩阵，即完成矩阵按照对角线进行排序。

​		最后，原矩阵就是答案。

```c++
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if(m == 1 || n == 1)
            return mat;
        for(int i=m-1; i>0; i--){
            vector<int> cur;
            int index = 0;
            while(index < n && i+index < m)
                cur.emplace_back(mat[i+index][index++]);
            sort(cur.begin(), cur.end());
            index = 0;
            while(index < n && i+index < m)
                mat[i+index][index++] = cur[index];
        }
        for(int i=0; i<n; i++){
            vector<int> cur;
            int index = 0;
            while(index < m && i+index < n)
                cur.emplace_back(mat[index][i+index++]);
            sort(cur.begin(), cur.end());
            index = 0;
            while(index < m && i+index < n)
                mat[index][i+index++] = cur[index];
        }
        return mat;
    }
};
```

