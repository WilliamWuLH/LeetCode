## Reshape the Matrix

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two **positive** integers **r** and **c** representing the **row** number and **column** number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same **row-traversing** order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

**Example 1:**

```
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
```

**Example 2:**

```
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
```

**Note:**

1. The height and width of the given matrix is in range [1, 100].
2. The given r and c are all positive.

#### 二维数组的一维表示：

​		假定二维数组的行数为 r，列数为 c。

​		把二维数组中的元素表示为一维的形式：二维坐标为 ( i , j )，一维表示为 i * c + j 。

​		把一维数组中的元素表示为二维的形式：一维表示是 k，二维坐标为 ( k / c , k % c ) 。

```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int origr = nums.size(), origc = nums[0].size();
        if(origr * origc != r * c)
            return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0; i<r*c; i++)
            ans[i / c][i % c] = nums[i / origc][i % origc];
        return ans;
    }
};
```

