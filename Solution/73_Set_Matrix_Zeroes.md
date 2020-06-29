## Set Matrix Zeroes

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

