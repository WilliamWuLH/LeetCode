## Search a 2D Matrix

Write an efficient algorithm that searches for a value in an `m x n` matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
```

**Example 2:**

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
```

**Example 3:**

```
Input: matrix = [], target = 0
Output: false
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `0 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

#### 矩阵的二分查找：

​		这个 left 和 right 的判断卡了我好久，果然二分查找的难点就在于边界和中间值的选取判断。

​		你的边界可以是能取到的最大边界，也可以是不能取到的最小边界，也可以是混合起来。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size()-1;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        if(target < matrix[left][0] || target > matrix[right][matrix[0].size()-1])
            return false;
        while(left < right){
            int mid = left + (right-left)/2;
            if(matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >= target){
                left = mid;
                right = mid;
                break;
            }
            if(matrix[mid][0] > target)
                right = mid-1;
            else if(matrix[mid][matrix[0].size()-1] < target)
                left = mid+1;
        }
        int row = left;
        left = 0;
        right = matrix[0].size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] > target)
                right = mid-1;
            else if(matrix[row][mid] < target)
                left = mid+1;
        }
        if(matrix[row][left] == target)
            return true;
        else
            return false;
    }
};
```

