## Maximal Square

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, *find the largest square containing only* `1`'s *and return its area*.

**Example 1:**

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

**Example 2:**

```
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

**Example 3:**

```
Input: matrix = [["0"]]
Output: 0
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` is `'0'` or `'1'`.

#### 确定正方形的左上角，逐层判断其边界是否满足条件：

```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        for(int i=0; i<matrix.size()-ans; i++){
            for(int j=0; j<matrix[i].size()-ans; j++){
                if(matrix[i][j] == '0')
                    continue;
                ans = max(ans, 1);
                int len = 1,flag = 1;
                while(flag){
                    if(i+len >= matrix.size() || j+len >= matrix[i].size() )
                        break;
                    for(int k=0; k<=len; k++){
                        if(matrix[i+len][j+k] == '0' || matrix[i+k][j+len] == '0'){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        ans = max(ans, len+1);
                        len++;
                    }
                }
            }
        }
        return ans*ans;
    }
};
```

