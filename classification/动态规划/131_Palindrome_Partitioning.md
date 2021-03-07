## Palindrome Partitioning

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.

A **palindrome** string is a string that reads the same backward as forward.

**Example 1:**

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Example 2:**

```
Input: s = "a"
Output: [["a"]]
```

**Constraints:**

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

#### 动态规划预处理 + 回溯：

​		由于需要求出字符串 s 的所有分割方案，因此我们考虑使用搜索 + 回溯的方法枚举所有可能的分割方法并进行判断。

​		假设我们当前搜索到字符串的第 i 个字符，且 s \[ 0 .. i−1 \] 位置的所有字符已经被分割成若干个回文串，并且分割结果被放入了答案数组 cur_ans 中，那么我们就需要枚举下一个回文串的右边界 j，使得 s \[ i .. j \] 是一个回文串。

​		因此，我们可以从 i 开始，从小到大依次枚举 j。对于当前枚举的 j 值，我们使用双指针的方法判断 s \[ i .. j \] 是否为回文串：如果 s \[ i .. j \] 是回文串，那么就将其加入答案数组 cur_ans 中，并以 j + 1 作为新的 i 进行下一层搜索，并在未来的回溯时将 s \[ i .. j \] 从 cur_ans 中移除。

​		如果我们已经搜索完了字符串的最后一个字符，那么就找到了一种满足要求的分割方法。

​		当我们在判断 s \[ i .. j \] 是否为回文串时，常规的方法是使用双指针分别指向 i 和 j，每次判断两个指针指向的字符是否相同，直到两个指针相遇。然而这种方法会产生重复计算。

​		因此，我们可以将字符串 s 的每个子串 s \[ i .. j \] 是否为回文串预处理出来，使用动态规划即可。预处理完成之后，我们只需要 O(1) 的时间就可以判断任意 s \[ i .. j \] 是否为回文串了。 

参考：[力扣官方题解](https://leetcode-cn.com/problems/palindrome-partitioning/solution/fen-ge-hui-wen-chuan-by-leetcode-solutio-6jkv/)

```c++
class Solution {
private:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> cur_ans;
    int n;
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        dp.resize(n, vector<bool>(n, true));

        for(int i=1; i<n; i++){
            for(int j=0; j<n && j+i<n; j++)
                dp[j][j+i] = (s[j] == s[j+i]) && dp[j+1][j+i-1];
        }
        dfs(s, 0);
        return ans;
    }
    void dfs(string &s, int start){
        if(start >= n){
            ans.emplace_back(cur_ans);
            return;
        }
        for(int i=start; i<n; i++){
            if(dp[start][i]){
                cur_ans.emplace_back(s.substr(start, i-start+1));
                dfs(s, i+1);
                cur_ans.pop_back();
            }
        }
        return;
    }
};
```

