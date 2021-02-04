## Get Equal Substrings Within Budget

You are given two strings `s` and `t` of the same length. You want to change `s` to `t`. Changing the `i`-th character of `s` to `i`-th character of `t` costs `|s[i] - t[i]|` that is, the absolute difference between the ASCII values of the characters.

You are also given an integer `maxCost`.

Return the maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t`with a cost less than or equal to `maxCost`.

If there is no substring from `s` that can be changed to its corresponding substring from `t`, return `0`.

**Example 1:**

```
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
```

**Example 2:**

```
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
```

**Example 3:**

```
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
```

**Constraints:**

- `1 <= s.length, t.length <= 10^5`
- `0 <= maxCost <= 10^6`
- `s` and `t` only contain lower case English letters.

#### 前缀和 + 二分查找：

​		将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 \|s\[i\] - t\[i\]\| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

​		用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

​		如果可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

​		如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

​		首先计算前缀和，通过前缀和可以计算得到从数组任意一个元素开头并且以数组任意一个元素结束的连续子字符串的开销，通过前缀和可以进行记忆化存储，减少不必要的重复计算。

​		有了前缀和之后，我们就要找到字符串中满足变更字符串的开销小于最大预算的最长子字符串，一开始是使用顺序判断，但是对于大数据（较长的字符串）时会超出时间限制。

​		所以之后采用二分查找，虽然可以通过，但是时间消耗还是很大，而且需要开辟空间存储前缀和。

```c++
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> sum(n+1, 0);
        for(int i=0; i<n; i++)
            sum[i+1] = sum[i] + abs(s[i] - t[i]);
        int ans = 0;
        for(int i=0; i<n; i++){
            int l = i, r = n+1;
            while(l < r){
                int mid = (r - l) / 2 + l;
                if(sum[mid] - sum[i] > maxCost)
                    r = mid;
                else if(sum[mid] - sum[i] <= maxCost)
                    l = mid + 1;
            }
            ans = max(ans, l - 1 - i);
        }
        return ans;
    }
};
```

#### 滑动窗口 + 双指针：

​		由于是求连续的子字符串，所以可以考虑使用滑动窗口进行求解，而且是求最大长度的子字符串，所以可以考虑使用双指针。

​		首先确定好怎么表示这个滑动窗口，我们本题使用双指针，其中左指针指向当前子字符串的开头，右指针指向当前子字符串的结尾，左右指针中间夹着的就是我们当前的滑动窗口（子字符串）。我们使用一个变量 sum 来记录当前滑动窗口中的这个子字符串进行变更的时候需要的开销，并且根据这个 sum 来判断滑动窗口中的这个子字符串是否符合题目要求的最大预算。

​		然后我们来看滑动窗口，滑动窗口中的子字符串就是当前我们需要判断是否符合题目要求（变更字符串的最大预算小于等于 maxCost）的字符串，如果满足 sum 小于等于 maxCost，说明子字符串符合要求，可以更新答案。如果不符合最大预算，说明滑动窗口中的这个子字符串的 sum 太大了，左指针需要向右移动。

​		同时，在滑动窗口移动的过程中，不管滑动窗口中的子字符串是否符合，我们的右指针每次都可以向右移动，为什么？我们分情况讨论：如果子字符串符合要求，说明滑动窗口还可以再扩大，此时左指针不用变，右指针需要向右移动来扩大滑动窗口；如果子字符串不符合要求，说明滑动窗口需要移动进行下一个子字符串的判断，所以右指针需要向右移动，同时左指针也要向右移动。

​		在滑动窗口移动的过程中不断判断并且更新答案，最后返回答案，其实也是滑动窗口最后的大小。

```c++
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), ans = 0;
        int l = 0, r = 0, sum = 0;
        while(r < n){
            sum += abs(s[r] - t[r++]);
            if(sum <= maxCost)
                ans = max(ans, r - l);
            else
                sum -= abs(s[l] - t[l++]);
        }
        return ans;
    }
};
```

