## Maximal Rectangle

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return *its area*.

**Example 1:**

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
```

**Example 2:**

```
Input: matrix = []
Output: 0
```

**Example 3:**

```
Input: matrix = [["0"]]
Output: 0
```

**Example 4:**

```
Input: matrix = [["1"]]
Output: 1
```

**Example 5:**

```
Input: matrix = [["0","0"]]
Output: 0
```

**Constraints:**

- `rows == matrix.length`
- `cols == matrix.length`
- `0 <= row, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`.

#### 单调栈：

​		按行讨论：把当前行和该行上面的全部行看作是一个柱状图。

​		很直观的，由每一列上的字符 '1' 形成了柱状图的每一条柱子，每一条柱子的高度是多少完全取决于该列上连续的字符 '1' 有多少，而且当前行上的该列应该为字符 '1'，如果被字符 '0' 截断了则不能算入柱子的高度。

​		我们得到了柱状图中每一条柱子的高度，就可以应用单调栈来求解这个柱状图的最大矩形面积。

​		把矩阵的每一行都讨论一次，最终就可以得到整个矩阵的最大矩形面积（'1' 矩形）。

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int vlen = matrix.size();
        if(vlen == 0)
            return 0;
        int hlen = matrix[0].size();
        int ans = 0;
        int height[hlen+1];
        memset(height, 0 ,(hlen+1)*sizeof(int));
        for(int i=0; i<vlen; i++){
            stack<int> s;
            matrix[i].push_back('0');
            for(int j=0; j<hlen+1; j++){
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
                while(!s.empty() && height[ s.top() ] > height[j]){
                    int h = height[ s.top() ];
                    s.pop();
                    int left = s.empty() ? -1 : s.top();
                    int right = j;
                    ans = max(ans, h * (right - left - 1));
                }
                s.push(j);
            }
        }
        return ans;
    }
};
```

