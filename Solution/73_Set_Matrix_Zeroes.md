## Set Matrix Zeroes

Given an `*m* x *n*` matrix. If an element is **0**, set its entire row and column to **0**. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

**Follow up:**

- A straight forward solution using O(*m**n*) space is probably a bad idea.
- A simple improvement uses O(*m* + *n*) space, but still not the best solution.
- Could you devise a constant space solution?

**Example 1:**

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^S31 <= matrix[i][j] <= 2^31 - 1`

#### 统计行列：

​			第一遍遍历，统计需要清零的行列。

​			第二遍遍历，清零矩阵的特定行。

​			第三遍遍历，清零矩阵的特定列。

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x(matrix.size(), 0);
        vector<int> y(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    x[i] = 1;
                    y[j] = 1;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            if(x[i]){
                for(int j=0; j<matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }                
            }
        }
        for(int i=0; i<matrix[0].size(); i++){
            if(y[i]){
                for(int j=0; j<matrix.size(); j++){
                    matrix[j][i] = 0;
                }                
            }
        }
    }
};
```

