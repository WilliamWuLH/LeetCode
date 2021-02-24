## Score of Parentheses

Given a balanced parentheses string `S`, compute the score of the string based on the following rule:

- `()` has score 1
- `AB` has score `A + B`, where A and B are balanced parentheses strings.
- `(A)` has score `2 * A`, where A is a balanced parentheses string.

**Example 1:**

```
Input: "()"
Output: 1
```

**Example 2:**

```
Input: "(())"
Output: 2
```

**Example 3:**

```
Input: "()()"
Output: 2
```

**Example 4:**

```
Input: "(()(()))"
Output: 6
```

**Note:**

1. `S` is a balanced parentheses string, containing only `(` and `)`.
2. `2 <= S.length <= 50`

#### 方法一：栈

​		简单思路，很直观的代码如下：

```c++
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> t;
        for(auto &i : S){
            if(i == '(')
                t.push(-1);
            else{
                int sum = 0;
                while(t.top() != -1){
                    sum += t.top();
                    t.pop();
                }
                t.pop();
                sum = sum == 0 ? 1 : 2 * sum;
                t.push(sum);
            }
        }
        int ans = 0;
        while(! t.empty()){
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};
```

#### 方法一：栈 + 优化

​		字符串 S 中的每一个位置都有一个 “ 深度 ”，即该位置外侧嵌套的括号数目。例如，字符串 ( ( ) ( . ( ) ) ) 中的 . 的深度为 2，因为它外侧嵌套了 2 层括号：( ( . ) ) 。

​		我们用一个栈来维护当前所在的深度，以及每一层深度的得分。当我们遇到一个左括号 ( 时，我们将深度加一，并且新的深度的得分置为 0。当我们遇到一个右括号 ) 时，我们将当前深度的得分乘二并加到上一层的深度。这里有一种例外情况，如果遇到的是 ( ) ，那么只将得分加一。

​	下面给出了字符串 ( ( ) ( ( ) ) ) 每次对应的栈的情况：

- [0, 0] (
- [0, 0, 0] ( (
- [0, 1] ( ( )
- [0, 1, 0] ( ( ) (
- [0, 1, 0, 0] ( ( ) ( (
- [0, 1, 1] ( ( ) ( ( )
- [0, 3] ( ( ) ( ( ) )
- [6] ( ( ) ( ( ) ) )

**参考：[力扣 (LeetCode)](https://leetcode-cn.com/problems/score-of-parentheses/solution/gua-hao-de-fen-shu-by-leetcode/)**

```c++
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> t;
        t.push(0);
        for(auto &i : S){
            if(i == '(')
                t.push(0);
            else{
                int cur = t.top();
                t.pop();
                int pre = t.top();
                t.pop();
                t.push(pre + max(2 * cur, 1));
            }
        }
        return t.top();
    }
};
```

#### 方法二：统计核心的数目

​		事实上，我们可以发现，只有 ( ) 会对字符串 S 贡献实质的分数，其它的括号只会将分数乘二或者将分数累加。因此，我们可以找到每一个 ( ) 对应的深度 x，那么答案就是 2 ^ x 的累加和。

**参考：[力扣 (LeetCode)](https://leetcode-cn.com/problems/score-of-parentheses/solution/gua-hao-de-fen-shu-by-leetcode/)**

```c++
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, depth = 0, n = S.length();
        for(int i=0; i<n; i++){
            if(S[i] == '(')
                depth++;
            else{
                depth--;
                if(S[i-1] == '(')
                    ans += 1 << depth;
            }
        }
        return ans;
    }
};
```

#### 