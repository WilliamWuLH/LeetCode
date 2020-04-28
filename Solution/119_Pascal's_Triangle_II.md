## Pascal's Triangle II

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

