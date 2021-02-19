## Minimum Remove to Make Valid Parentheses

Given a string s of `'('` , `')'` and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Example 4:**

```
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is one of `'('` , `')'` and lowercase English letters`.`

#### 移除无效的括号：

​		本题给定一个由 ' ( '、' ) ' 和小写字母组成的字符串 s。我们需要从字符串中删除最少数目的 ' ( ' 或者 ' ) ' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。并且要返回任意一个合法字符串。

​		首先我们对给定的字符串 s 进行正向遍历，目的是去除无效的右括号 ' ) '，并且统计剩余的左括号的个数 count。初始化答案字符串为 ans = ""，剩余左括号的个数 count = 0。正向遍历 s，如果当前的字符 i 不是右括号 ' ) ' 或者当前剩余左括号的个数 count 大于 0，说明此时这个字符 i 是有用的，可以添加到答案字符串 ans 中，并且判断如果字符是左括号，则剩余左括号的个数 count 要加一，如果字符是右括号，则可以和前面的一个左括号形成一个有效的括号对，所以剩余左括号的个数 count 要减一。（为什么可以减一？因为能进入这层判断的前提是 count 大于 0，即前面一定有一个剩余的左括号）。

​		接下来判断剩余左括号的个数 count，如果 count 等于 0，说明没有剩余左括号，所有括号都形成了有效的括号对，可以直接返回答案字符串。

​		如果 count 不等于 0，则 count 一定大于 0，我们需要删除剩余无效的左括号。此时多余无效的左括号可能出现在两个位置，即字符串的左侧或者字符串的右侧，所以可能出现的情况有三种：都在字符串的左侧，都在字符串的右侧和字符串的左侧和右侧都有。那么我们应该怎么删除这些多余的无效左括号呢？

​		其实仔细思考后发现很简单，我们直接对字符串进行反向遍历（从后往前遍历）并且进行无效左括号的删除就可以了。为什么？首先，我们通过之前的正向遍历已经统计出需要删除的无效左括号的个数，所以我们知道有多少左括号是一定要删除的，其中，在字符串右侧的所以左括号一定都是不合法的，是一定需要删除的，所以我们可以毫不犹豫的直接删除字符串右侧的左括号，并且实时更新剩余无效左括号的个数。如果删除全部字符串右侧的无效左括号之后还有剩余左括号需要删除，我们可以继续删除在字符串左边的左括号，因为没有固定说一定要删除哪些位置的左括号，所以此时的左括号都可以和相应的右括号形成合法的括号对，所以不妨我们删除最靠右边的这些左括号，一直删除到没有剩余的无效左括号停止。此时的答案字符串就是最终答案。

```c++
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int count = 0;
        for(auto &i : s){
            if(i != ')' || count > 0){
                ans += i;
                if(i == '(')
                    count++;
                else if(i == ')')
                    count--;
            }
        }
        if(count == 0)
            return ans;
        int n = ans.length();
        for(int i=n-1; i>=0; i--){
            if(ans[i] == '('){
                ans.erase(ans.begin() + i);
                count--;
            }
            if(count == 0)
                break;
        }
        return ans;
    }
};
```

