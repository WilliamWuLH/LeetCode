## Search a 2D Matrix II

Write an efficient algorithm that searches for a `target` value in an `m x n` integer `matrix`. The `matrix` has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

**Example 1:**

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

**Example 2:**

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `-10^9 <= matix[i][j] <= 10^9`
- All the integers in each row are **sorted** in ascending order.
- All the integers in each column are **sorted** in ascending order.
- `-10^9 <= target <= 10^9`

#### 对矩阵的每一行进行二分查找：

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        for(int i=0; i<matrix.size(); i++){
            int headh = 0, tailh = matrix[0].size();
            if(matrix[i][tailh-1] < target)
                continue;
            if(matrix[i][0] > target)
                return false;
            while(headh < tailh){
                int midh = headh + (tailh - headh)/2;
                if(matrix[i][midh] == target)
                    return true;
                else if(matrix[i][midh] < target){
                    headh = midh+1;
                }
                else if(matrix[i][midh] > target){
                    tailh = midh;
                }
            }
        } 
        return false;
    }
};
```

