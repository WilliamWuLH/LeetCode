## Letter Case Permutation

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return *a list of all possible strings we could create*. You can return the output in **any order**.

**Example 1:**

```
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
```

**Example 2:**

```
Input: S = "3z4"
Output: ["3z4","3Z4"]
```

**Example 3:**

```
Input: S = "12345"
Output: ["12345"]
```

**Example 4:**

```
Input: S = "0"
Output: ["0"]
```

**Constraints:**

- `S` will be a string with length between `1` and `12`.
- `S` will consist only of letters or digits.

#### 回溯法：

​		题目给定一个字符串 S，通过将字符串 S 中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

​		本题就是求全排列的问题，可以通过回溯法实现。我们需要维持当前的字符串 s，判断到的字符串位置 pos 和当前记录的全排列答案。

​		回溯的边界条件是当当前需要判断的位置大于字符串长度时，说明当前的字符串中全部字符已经判断完毕，是一种排列情况，可以添加到最终的答案中并且返回。

​		当当前需要判断的字符串位置还小于字符串的长度时，我们找到下一个字符串中是英文字母的位置，该位置可以转变大小写以形成不同的排列。会出现两种情况：

- 情况一：当字符串后续没有英文字母时，说明已经无法形成其他的排列了，那么就把当前的字符串添加到答案中，并且返回。
- 情况二：当找到下一个字符串中的英文字母时，说明此时可以根据这个英文字母形成不一样的排列，我们首先可以递归下一层的判断（字符串的判断位置 pos 需要加一），然后根据这个英文字母的大小写进行字母的大小写转变，形成新的排列并且进入下一层的递归判断。

​		最后，回溯法结束返回，记录的答案就是最终的全排列。

```c++
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(S, 0, ans);
        return ans;
    }
    void backtrack(string s, int pos, vector<string> &ans){
        int n = s.length();
        if(pos >= n){
            ans.emplace_back(s);
            return;
        }
        while(pos < n && s[pos] >= '0' && s[pos] <= '9')
            pos++;
        if(pos == n){
            ans.emplace_back(s);
            return;
        }
        backtrack(s, pos+1, ans);
        if(s[pos] >= 'a' && s[pos] <= 'z')
            s[pos] = s[pos] - 'a' + 'A';
        else
            s[pos] = s[pos] - 'A' + 'a';
        backtrack(s, pos+1, ans);
        return;
    }
};
```

