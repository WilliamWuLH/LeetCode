## Evaluate Reverse Polish Notation

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

