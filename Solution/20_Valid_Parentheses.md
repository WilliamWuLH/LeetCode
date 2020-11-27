## Valid Parentheses

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

**Example 1:**

```
Input: s = "()"
Output: true
```

**Example 2:**

```
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```
Input: s = "(]"
Output: false
```

**Example 4:**

```
Input: s = "([)]"
Output: false
```

**Example 5:**

```
Input: s = "{[]}"
Output: true
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

#### 未完成队列：

​			遍历字符串，每次遇到 “ { ” “ [ ” “ ( ” 将其加入未完成队列中。

​			遇到 “ } ” “ ] ” “ ) ” 时，取出未完成队列的最后一个字符进行判断，正确就从未完成队列中除去，错误就返回 false。

​			最后如果未完成队列中还有字符，则返回 false，若未完成队列为空，则返回 true。

```c++
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        int count = 0;
        string front = "";
        for(int i=0;i<len;i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                front += s[i];
                count++;
            }
            if(count == 0)
                return false;
            if(s[i] == ')'){
                if(front[count-1] == '('){
                    front = front.substr(0,front.length()-1);
                    count--;
                }
                else
                    return false;
            }
            if(s[i] == ']'){
                if(front[count-1] == '['){
                    front = front.substr(0,front.length()-1);
                    count--;
                }
                else
                    return false;
            }
            if(s[i] == '}'){
                if(front[count-1] == '{'){
                    front = front.substr(0,front.length()-1);
                    count--;
                }
                else
                    return false;
            }
        }
        if(count == 0)
            return true;
        else
            return false;
    }
};
```

