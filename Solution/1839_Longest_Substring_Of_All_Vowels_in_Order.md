## Longest Substring Of All Vowels in Order

A string is considered **beautiful** if it satisfies the following conditions:

- Each of the 5 English vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`) must appear **at least once** in it.
- The letters must be sorted in **alphabetical order** (i.e. all `'a'`s before `'e'`s, all `'e'`s before `'i'`s, etc.).

For example, strings `"aeiou"` and `"aaaaaaeiiiioou"` are considered **beautiful**, but `"uaeio"`, `"aeoiu"`, and `"aaaeeeooo"` are **not beautiful**.

Given a string `word` consisting of English vowels, return *the **length of the longest beautiful substring** of* `word`*. If no such substring exists, return* `0`.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**

```
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
```

**Example 2:**

```
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.
```

**Example 3:**

```
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.
```

**Constraints:**

- `1 <= word.length <= 5 * 10^5`
- `word` consists of characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

#### 滑动窗口 + 判断：

```c++
class Solution {
public:
    int longestBeautifulSubstring(string w) {
        int ans = 0, n = w.length(), l = 0;
        for(int i=0; i<n; i++){
            if(l == 0){
                if(w[i] == 'a')
                    l = 1;
                continue;
            }
            // have     
            else{
                // same
                if(w[i] == w[i-1])
                    ++l;
                // not
                else if((w[i-1] == 'a' && w[i] =='e') || (w[i-1] == 'e' && w[i] =='i') || (w[i-1] == 'i' && w[i] =='o') || (w[i-1] == 'o' && w[i] =='u'))
                    ++l;
                else if(w[i] == 'a')
                    l = 1;
                else
                    l = 0;
            }
            if(w[i] == 'u' && l > 0)
                ans = max(ans, l);
        }
        return ans;
    }
};
```

