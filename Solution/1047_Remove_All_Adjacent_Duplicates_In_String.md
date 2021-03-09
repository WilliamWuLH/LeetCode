## Remove All Adjacent Duplicates In String

Given a string `S` of lowercase letters, a *duplicate removal* consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed the answer is unique.

**Example 1:**

```
Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

**Note:**

1. `1 <= S.length <= 20000`
2. `S` consists only of English lowercase letters.

#### 栈：

​		定义一个 string 变量作为一个栈，如果当前的 string 变量 ans 不为空而且最后的字符和给定字符串 S 的下一个字符相同，说明出现重复字符，可以把 ans 的最后一个字符出栈，否则，把给定字符串 S 的下一个字符入栈。

​		最后得到的 ans 就是答案。

参考：[string](http://www.cplusplus.com/reference/string/string/)

```c++
class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for(auto &c : S){
            if(! ans.empty() && ans.back() == c)
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
```

