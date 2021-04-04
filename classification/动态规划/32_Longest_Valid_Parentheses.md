## Longest Valid Parentheses

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

**Example 2:**

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Example 3:**

```
Input: s = ""
Output: 0
```

**Constraints:**

- `0 <= s.length <= 3 * 10^4`
- `s[i]` is `'('`, or `')'`.

#### 动态规划：

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
	    int ans = 0;
        int len = s.length();
		vector<int> dp(len, 0);
		for(int i=1; i<len; i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = i-1>0 ? dp[i-2]+2 : 2;
                }
                else if( i-1-dp[i-1] >=0 && s[i-1-dp[i-1]] == '('){
                    if( i-dp[i-1]-2 >= 0){
                       dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    }
                    else{
                        dp[i] = dp[i-1] + 2;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

#### 用stack栈 存 “(” 的位置：

​		在栈中的栈底元素是此时有效括号字符串的开始位置。

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
	    int ans = 0;
        int len = s.length();
		stack<int> front;
        front.push(-1);
		for(int i=0; i<len; i++){
            if(s[i] == '(')
                front.push(i);
            else{
                front.pop();
                if(front.empty())
                    front.push(i);
                else
                    ans = max(ans, i-front.top());
            }
        }
        return ans;
    }
};
```

