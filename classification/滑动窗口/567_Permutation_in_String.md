## Permutation in String

Given two strings **s1** and **s2**, write a function to return true if **s2** contains the permutation of **s1**. In other words, one of the first string's permutations is the **substring** of the second string.

**Example 1:**

```
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```
Input:s1= "ab" s2 = "eidboaoo"
Output: False
```

**Constraints:**

- The input strings only contain lower case letters.
- The length of both given strings is in range [1, 10,000].

#### 统计字符数量 + 滑动窗口：

​		给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。换句话说，第一个字符串的排列之一是第二个字符串的子串。

​		当我们在进行判断时，不需要列举出所有 s1 的排列，我们仅需要统计在 s1 中每一个字符出现的次数，然后在 s2 中的子串里面找有没有和 s1 的字符出现次数相同的，如果每一个字符在 s1 中的出现次数和在 s2 的子串中的出现次数相同，则说明一定有 s1 的排列之一是现在 s2 的当前子串。

​		在进行具体编码时，我们可以先判断字符串 s1 的长度是否大于字符串 s2，如果 s1 的长度比 s2 长则直接返回 false。我们需要开辟两个长度为 26 的 int 型数组，用于统计 s1 中的字符数量和 s2 的子串的字符数量。

​		由于 s2 的子串是连续的，并且因为要是 s1 的排列之一，所以子串的长度一定是等于 s1 的长度，所以我们规定在 s2 中的子串长度等于 s1 的长度。此时我们就可以采用滑动窗口的思想，假设子串的长度为 n1，我们先统计 s2 中前 n1 个字符的数量，判断是否等于 s1 中的字符数量，相等直接返回 true，不相等则滑动窗口，去除窗口前一个字符，添加窗口后面第一个字符，即更新窗口内的字符数量，然后再判断，一直判断到找到答案或者遍历完整个 s2。

​		具体代码如下：

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1count[26], s2count[26];
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2)
            return false;
        memset(s1count, 0, sizeof(int)*26);
        memset(s2count, 0, sizeof(int)*26);
        for(auto &i : s1)
            s1count[ i-'a' ]++;
        for(int i=0; i<n1; i++)
            s2count[ s2[i]-'a' ]++;
        for(int i=n1-1; i<n2; i++){
            if(i > n1-1){
                s2count[ s2[i]-'a' ]++;
                s2count[ s2[i-n1]-'a' ]--;
            }
            int j=0;
            for(j=0; j<26; j++)
                if(s1count[j] != s2count[j])
                    break;
            if(j == 26)
                return true;
        }
        return false;
    }
};
```

