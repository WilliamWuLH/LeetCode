## Pascal's Triangle II

Given an integer `rowIndex`, return the `rowIndexth` row of the Pascal's triangle.

Notice that the row index starts from **0**.

**Follow up:**

Could you optimize your algorithm to use only *O*(*k*) extra space?

**Example 1:**

```
Input: rowIndex = 3
Output: [1,3,3,1]
```

**Example 2:**

```
Input: rowIndex = 0
Output: [1]
```

**Example 3:**

```
Input: rowIndex = 1
Output: [1,1]
```

**Constraints:**

- `0 <= rowIndex <= 40`

#### 动态规划：

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        rowIndex++;
        int level = rowIndex;
        while(rowIndex){
            vector<int> cur;
            cur.push_back(1);
            for(int i=1; i<level-rowIndex; i++)
                cur.push_back(ans[i-1] + ans[i]);
            if(level-rowIndex)
                cur.push_back(1);
            ans = cur;
            rowIndex--;
        }
        return ans;
    }
};
```

