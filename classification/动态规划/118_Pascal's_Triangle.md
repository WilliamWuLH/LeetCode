## Pascal's Triangle

Given a non-negative integer *numRows*, generate the first *numRows* of Pascal's triangle.

**Example:**

```
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

#### 动态规划：

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int level = numRows;
        while(numRows){
            vector<int> cur;
            cur.push_back(1);
            for(int i=1; i<level-numRows; i++)
                cur.push_back(ans[level-numRows-1][i-1] + ans[level-numRows-1][i]);
            if(level-numRows)
                cur.push_back(1);
            ans.push_back(cur);
            numRows--;
        }
        return ans;
    }
};
```

