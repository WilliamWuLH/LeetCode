## Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

**Note:**

- Division between two integers should truncate toward zero.
- The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

**Example 1:**

```
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**

```
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**Example 3:**

```
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

#### 逆波兰表达式求值：使用栈

​		 [逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437) 

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i : tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int ans = 0;
                if(i == "+")
                    ans = a + b;
                else if(i == "-")
                    ans = a - b;
                else if(i == "*")
                    ans = a * b;
                else if(i == "/")
                    ans = a / b;
                s.push(ans);
            }
            else{
                int temp = stoi(i);
                s.push(temp);
            }
        }
        return s.top();
    }
};
```

