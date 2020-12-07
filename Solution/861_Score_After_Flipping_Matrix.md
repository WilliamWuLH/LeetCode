## Score After Flipping Matrix

We have a two dimensional matrix `A` where each value is `0` or `1`.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all `0`s to `1`s, and all `1`s to `0`s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

**Example 1:**

```
Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```

**Note:**

1. `1 <= A.length <= 20`
2. `1 <= A[0].length <= 20`
3. `A[i][j]` is `0` or `1`.

#### 贪心：

​		首先，为了得到更高的 Score，矩阵每一行的第一个数字必须是 1，这就是**第一层的贪心**。

​		所以第一步：遍历矩阵的每一行，如果某一行的第一个数字不是 1，则进行翻转，注意！进行行翻转时要记录该翻转，因为这个翻转不只是影响到这一行的第一个数，而是影响了这一行的每个数。

​		然后，我们要使得 Score 进一步增大，就是从每个数的高位不断讨论到低位，使得每个数的越高位的 1 越多越好，这就是**第二层的贪心**。

​		为了使得 Score 最大，我们要让每个列中 1 的数目尽可能多。因此，我们扫描除了最左边的列以外的每一列，如果该列 0 的数目多于 1 的数目，就翻转该列，其他的列则保持不变。

​		实际编写代码时，我们无需修改原矩阵。详细可看代码实现：

```c++
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int ans = 0, flag = 0;
        for(int i=0; i<m; i++){
            if(A[i][0] == 0)
                flag &= 1<<;
        }
        ans += m * pow(2, n-1);
        for(int i=1; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++)
                if((A[j][i] == 1 && flag[j] == 0) || (A[j][i] == 0 && flag[j] == 1))
                    count++;
            if(count > m/2)
                ans += count * pow(2, n-1-i);
            else
                ans += (m-count) * pow(2, n-1-i);
        }
        return ans;
    }
};
```

