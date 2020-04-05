## Search a 2D Matrix II

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

