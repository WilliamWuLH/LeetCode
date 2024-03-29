## Rotate Image

You are given an *n* x *n* 2D `matrix` representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

**Example 2:**

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

**Example 3:**

```
Input: matrix = [[1]]
Output: [[1]]
```

**Example 4:**

```
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]
```

**Constraints:**

- `matrix.length == n`
- `matrix[i].length == n`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`

#### 2021.4.25 再回首：

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int t[4] = {0,0,0,0};
        for(int i=0; i<n; i++){
            for(int j=i; j<n-1-i; j++){
                t[0] = matrix[i][j];
                t[1] = matrix[j][n-1-i];
                t[2] = matrix[n-1-i][n-1-j];
                t[3] = matrix[n-1-j][i];
                matrix[i][j] = t[3];
                matrix[j][n-1-i] = t[0];
                matrix[n-1-i][n-1-j] = t[1];
                matrix[n-1-j][i] = t[2];
            }
        }
        return;
    }
};
```



#### 建立辅助矩阵 + 直接旋转：

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int len = matrix.size();
        for(int i=0; i<len; i++){
            vector<int> nums = temp[i];
            for(int j=0; j<len; j++){
                matrix[j][len-1-i] = nums[j];
            }
        }
    }
};
```

