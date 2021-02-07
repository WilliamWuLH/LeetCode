## Shortest Distance to a Character

Given a string `s` and a character `c` that occurs in `s`, return *an array of integers `answer` where* `answer.length == s.length` *and* `answer[i]` *is the shortest distance from* `s[i]` *to the character* `c` *in* `s`.

**Example 1:**

```
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
```

**Example 2:**

```
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s[i]` and `c` are lowercase English letters.
- `c` occurs at least once in `s`.

#### 记录字符位置 + 遍历判断：

​		给定一个字符串 s 和一个字符 c。返回一个代表字符串 s 中每个字符到字符串 s 中的字符 c 的最短距离的数组。

​		首先，遍历字符串 s，找出字符串 s 中所有字符 c，并且记录每一个字符 c 的位置。

​		然后重新再次遍历字符串 s，如果遍历到的字符 s[i] 为字符 c，则记录此时的最短距离为 0。如果遍历到的字符 s[i] 不是字符 c，则在记录有每一个字符 c 的位置中进行选择，选出比当前字符位置 i 大的第一个字符 c 的位置 cpos[index]，如果确实没有比当前字符位置 i 大的字符 c 的位置，则取字符 c 的位置中的最大那个位置。

​		接着根据字符 c 的位置 cpos[index] 进行判断，如果此时 index 为 0，说明前面没有字符 c，所以此时的最短距离就是 abs(cpos[index] - i)，如果此时 index 不是 0，说明前一个字符 c 的位置也需要考虑一下，所以应该取 abs(cpos[index]-i) 和 abs(cpos[index-1]-i) 中的最小值。

​		最后返回经过以上遍历判断之后的最短距离。

```c++
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> cpos, ans(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] == c)
                cpos.emplace_back(i);
        }
        int index = 0;
        for(int i=0; i<n; i++){
            if(s[i] != c){
                while(cpos[index] < i && index < cpos.size()-1)
                    index++;
                ans[i] = index == 0 ? abs(cpos[index] - i) : min(abs(cpos[index]-i), abs(cpos[index-1]-i));
            }
        }
        return ans;
    }
};
```

