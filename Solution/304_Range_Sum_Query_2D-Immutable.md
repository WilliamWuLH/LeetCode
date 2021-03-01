## Range Sum Query 2D - Immutable

Given a 2D matrix *matrix*, find the sum of the elements inside the rectangle defined by its upper left corner (*row*1, *col*1) and lower right corner (*row*2, *col*2).

![Range Sum Query 2D](https://leetcode.com/static/images/courses/range_sum_query_2d.png)
The above rectangle (with the red border) is defined by (row1, col1) = **(2, 1)** and (row2, col2) = **(4, 3)**, which contains sum = **8**.

**Example:**

```
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
```

**Note:**

1. You may assume that the matrix does not change.
2. There are many calls to *sumRegion* function.
3. You may assume that *row*1 ≤ *row*2 and *col*1 ≤ *col*2.

#### 二维前缀和：

​		题目给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。

​		我们可以计算并且记录这个二维矩阵的二维前缀和，所谓的二维前缀和，就是给定一个点 ( r , c )，我们计算从点 ( 0 , 0 ) 到点 ( r , c ) 之间的这个矩阵中所有元素数值之和。为了计算方便，我们可以新增一行和一列，这一行和一列位于矩阵的上侧和左侧，作为初始值，所以行和列的数值全部是 0.

​		计算二维前缀和的方法和公式在代码中，十分简单易懂。然后在求二维区域的数值之和时和求二维前缀和思路大致相同，也在代码中很清楚。

```c++
class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = 0;
        if(r > 0)
            c = matrix[0].size();
        sum.resize(r+1, vector<int>(c+1, 0));
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```

