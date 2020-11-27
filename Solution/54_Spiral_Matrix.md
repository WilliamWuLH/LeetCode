## Spiral Matrix

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

#### 矩阵的层次遍历：

​		很直接很直观，规定一个层级，按照层级和四个方向进行遍历。

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int level = 0;
        int row = matrix.size();
        if(row == 0)
            return ans;
        int col = matrix[0].size();
        while(ans.size() < row*col){
            for(int i=level; i<col-level; i++)
                ans.push_back(matrix[level][i]);
            if(ans.size() == row*col)    break;
            for(int i=level+1; i<row-level; i++)
                ans.push_back(matrix[i][col-level-1]);
            if(ans.size() == row*col)    break;
            for(int i=col-level-2; i>=level; i--)
                ans.push_back(matrix[row-level-1][i]);
            if(ans.size() == row*col)    break;
            for(int i=row-level-2; i>level; i--)
                ans.push_back(matrix[i][level]);
            level++;
        }
        return ans;
    }
};
```

