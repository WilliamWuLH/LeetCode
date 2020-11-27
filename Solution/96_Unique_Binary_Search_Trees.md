## Unique Binary Search Trees

Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?

**Example:**

```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

**Constraints:**

- `1 <= n <= 19`

#### 数学题 + 记录 + 相乘 + 相加：

​			记录下从 0 到 n 之间的各个数 所可能构造出来的二叉查找树（二叉搜索树）的个数。

​			记录下来的原因是：之后的二叉查找树个数计算会用到之前的结果。

```c++
class Solution {
public:
    int numTrees(int n) {
        long table[1000];
        table[0] = 1;
        table[1] = 1;
        for(int i=2; i<=n; i++){
            table[i] = 0;
            for(int j=1; j<=i; j++){
                table[i] += (table[j-1] * table[i-j]);
            }
        }
        return table[n];
    }
};
```

