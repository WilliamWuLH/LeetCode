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

#### 2021.2.12 再回首

#### 线性递推

由组合数公式 $\mathcal{C}_n^m=\dfrac{n!}{m!(n-m)!}$ ，可以得到同一行的相邻组合数的关系

$\mathcal{C}_n^m= \mathcal{C}_n^{m-1} \times \dfrac{n-m+1}{m}$

由于 $\mathcal{C}_n^0=1$，利用上述公式我们可以在线性时间计算出第 n 行的所有组合数。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row[i] = 1LL * row[i - 1] * (rowIndex - i + 1) / i;
        }
        return row;
    }
};
```

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

