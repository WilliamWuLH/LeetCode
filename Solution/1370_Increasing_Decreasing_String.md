## Increasing Decreasing String

Given a string `s`. You should re-order the string using the following algorithm:

1. Pick the **smallest** character from `s` and **append** it to the result.
2. Pick the **smallest** character from `s` which is greater than the last appended character to the result and **append** it.
3. Repeat step 2 until you cannot pick more characters.
4. Pick the **largest** character from `s` and **append** it to the result.
5. Pick the **largest** character from `s` which is smaller than the last appended character to the result and **append** it.
6. Repeat step 5 until you cannot pick more characters.
7. Repeat the steps from 1 to 6 until you pick all characters from `s`.

In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return *the result string* after sorting `s` with this algorithm.

**Example 1:**

```
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
```

**Example 2:**

```
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
```

**Example 3:**

```
Input: s = "leetcode"
Output: "cdelotee"
```

**Example 4:**

```
Input: s = "ggggggg"
Output: "ggggggg"
```

**Example 5:**

```
Input: s = "spo"
Output: "ops"
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` contains only lower-case English letters.

#### 排序 + 顺序逆序遍历：

​		首先，对字符串进行排序。接下来：

1. **顺序遍历字符串**，把每一个各不相同的字符按顺序从字符串中取出来，并存到答案字符串中，把取出的字符从原字符串中删除。
2. **逆序遍历字符串**，把每一个各不相同的字符按顺序从字符串中取出来，并存到答案字符串中，把取出的字符从原字符串中删除。
3. 如果此时原始字符串中还有字符，说明字符还没有取完，重复 1-2 过程。

最后答案字符串为答案返回。

```c++
class Solution {
public:
    string sortString(string s) {
        string ans = "";
        sort(s.begin(), s.end());
        while(s.length()){
            char cur = s[0]+1;
            for(int i=0; i<s.length(); i++){
                if(s[i] != cur){
                    ans += s[i];
                    cur = s[i];
                    s.erase(s.begin()+i);
                    i--;
                }
            }
            if(s.length() == 0)
                break;
            cur += 1;
            for(int i = s.length()-1; i>=0; i--){
                if(s[i] != cur){
                    ans += s[i];
                    cur = s[i];
                    s.erase(s.begin()+i);
                }
            }
        }
        return ans;
    }
};
```

#### 统计各个字符的个数 + 顺序逆序组合：

​		首先统计字符串中各个字符的个数。

1. 顺序遍历字符表，把此时还有的字符添加到答案字符串中，并把该字符的个数减一。
2. 逆序遍历字符表，把此时还有的字符添加到答案字符串中，并把该字符的个数减一。
3. 判断答案字符串的长度是否和原始字符串的长度相等，如果不相等说明还有字符没有讨论，重复 1-2 步骤。

返回答案字符串。

```c++
class Solution {
public:
    string sortString(string s) {
        int a[26];
        int len = s.length();
        memset(a, 0, sizeof(int)*26);
        for(auto i : s)
            a[i-'a']++;
        s = "";
        while(s.length() < len){
            for(int i=0; i<26; i++){
                if(a[i]){
                    s += 'a'+i;
                    a[i]--;
                }
            }
            for(int i=25; i>=0; i--){
                if(a[i]){
                    s += 'a'+i;
                    a[i]--;
                }
            }
        }
        return s;
    }
};
```

