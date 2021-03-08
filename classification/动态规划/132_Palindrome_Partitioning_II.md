## Palindrome Partitioning II

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return *the minimum cuts needed* for a palindrome partitioning of `s`.

**Example 1:**

```
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

**Example 2:**

```
Input: s = "a"
Output: 0
```

**Example 3:**

```
Input: s = "ab"
Output: 1
```

**Constraints:**

- `1 <= s.length <= 2000`
- `s` consists of lower-case English letters only.

#### 动态规划：

​		设 f \[ i \] 表示字符串的前缀 s \[ 0 .. i \] 的最少分割次数。要想得出 f \[ i \] 的值，我们可以考虑枚举 s \[ 0 .. i \] 分割出的最后一个回文串，这样我们就可以写出状态转移方程：

​				$$ f[i] = \min_{0 \leq j < i} \{ f[j] \} + 1 $$

​		其中 s \[ j + 1 .. i \] 是一个回文串即我们枚举最后一个回文串的起始位置 j + 1，保证 s \[ j + 1 .. i \] 是一个回文串，那么 f \[ i \] 就可以从 f \[ j \] 转移而来，附加 1 次额外的分割次数。

​		注意到上面的状态转移方程中，我们还少考虑了一种情况，即 s \[ 0 .. i \] 本身就是一个回文串。此时其不需要进行任何分割，即：f \[ i \] = 0

​		那么我们如何知道 s \[ j + 1 .. i \] 或者 s \[ 0 .. i \] 是否为回文串呢？我们可以使用与「[ 131. Palindrome Partitioning ](https://leetcode.com/problems/palindrome-partitioning/)」中相同的预处理方法，将字符串 s 的每个子串是否为回文串预先计算出来，这样一来，我们只需要 O(1) 的时间就可以判断任意 s \[ i .. j \] 是否为回文串了。通过动态规划计算出所有的 f 值之后，最终的答案即为 f \[ n − 1 \]，其中 n 是字符串 s 的长度。

参考：[力扣官方题解](https://leetcode-cn.com/problems/palindrome-partitioning-ii/solution/fen-ge-hui-wen-chuan-ii-by-leetcode-solu-norx/)

```c++
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> ispal(n, vector<bool>(n, true));
        for(int l=1; l<n; l++){
            for(int start=0; start+l<n; start++)
                ispal[start][start+l] = (s[start] == s[start+l]) && ispal[start+1][start+l-1];
        }
        vector<int> split(n, INT_MAX);
        for(int i=0; i<n; i++){
            if(ispal[0][i])
                split[i] = 0;
            else{
                for(int j=0; j<i; j++){
                    if(ispal[j+1][i])
                        split[i] = min(split[i], split[j]+1);
                }
            }
        }
        return split[n-1];
    }
};
```

