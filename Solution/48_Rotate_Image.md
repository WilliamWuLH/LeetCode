## Rotate Image

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

