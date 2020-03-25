## Edit Distance

#### 动态规划：

​			看似很难，其实解法相当巧妙——大问题变成小问题——最优子结构性质

​			当其中某一个字符串的长度为 0 时，答案为另一个字符串的长度。

​			讨论两个字符串当前的字符：

- 如果当前的两个字符相同，则不需要进行任何操作，所以此时的编辑数为加入这两个字符之前的两个字符串的编辑数。
- 如果当前的两个字符不相同，说明需要进行操作，需要选择此时三个操作（插入字符 dp [ i ] [ j-1 ]，删去字符 dp [ i-1 ] [ j ]，替换字符 dp [ i-1 ] [ j-1 ] ）中编辑数最少的，作为此时两个字符串的编辑数。

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[len1+1][len2+1];
        for(int i=0; i<=len1; i++)
            dp[i][0] = i;
        for(int i=0; i<=len2; i++)
            dp[0][i] = i;
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
            }
        }
        return dp[len1][len2];
    }
};
```

