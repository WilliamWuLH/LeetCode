## Longest Substring with At Least K Repeating Characters

Given a string `s` and an integer `k`, return *the length of the longest substring of* `s` *such that the frequency of each character in this substring is greater than or equal to* `k`.

**Example 1:**

```
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
```

**Example 2:**

```
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of only lowercase English letters.
- `1 <= k <= 10^5`

#### 分治 + 递归：

​		对于字符串 s，如果存在某个字符 c，它的出现次数大于 0 且小于 k，则任何包含 c 的子串都不可能满足要求。也就是说，我们将字符串按照 c 切分成若干段，则满足要求的最长子串一定出现在某个被切分的段内，而不能跨越一个或多个段。因此，可以考虑分治的方式求解本题。

​		通过字符 c 切分若干段之后，对于每一段字符串继续进行上述操作，判断此时的子字符串是否存在新的字符 c 出现次数大于 0 且小于 k，如果没有则返回长度，如果有就继续进行，这就是递归的思路。

```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n-1, k);
    }
    int dfs(string &s, int start, int end, int &k){
        vector<int> count(26, 0);
        for(int i=start; i<=end; i++)
            count[s[i]-'a']++;
        char split = 0;
        for(int i=0; i<26; i++){
            if(count[i] > 0 && count[i] < k){
                split = i + 'a';
                break;
            }
        }
        if(split == 0)
            return end - start + 1;
        int cur = start;
        int ans = 0;
        while(cur <= end){
            while(cur <= end && s[cur] == split)
                cur++;
            if(cur > end)
                break;
            int new_start = cur;
            while(cur <= end && s[cur] != split)
                cur++;
            int len = dfs(s, new_start, cur-1, k);
            ans = max(ans, len);
        }
        return ans;
    }
};
```

#### 滑动窗口：

2021.2.27

**参考：[力扣官方题解](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/zhi-shao-you-kge-zhong-fu-zi-fu-de-zui-c-o6ww/)**