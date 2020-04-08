## Decode String

#### 栈：

​		由于字符串里面可能还嵌套了一层需要解码的字符串，即 " [ ] " 里面可能还有深一层的 " [ ] "，立刻马上可以想到的解法就是递归和栈。

​		给字符串需要复制的次数开辟一个辅助栈。

​		给此时需要被复制的字符串开辟一个辅助栈。

​		根据 " [ " 和 " ] " 判断需要入栈还是出栈。

```c++
class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int count = 0;
        stack<int> numstack;
        stack<string> ansstack;
        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i]))
                ans += s[i];
            else if(s[i] >= '0' && s[i] <= '9')
                count = count*10 + s[i]-'0';
            else if(s[i] == '['){
                ansstack.push(ans);
                numstack.push(count);
                ans = "";
                count = 0;
            }
            else if(s[i] == ']'){
                for(int j=0; j<numstack.top(); j++){
                    ansstack.top() += ans;
                }
                numstack.pop();
                ans = ansstack.top();
                ansstack.pop();
            }
        }
        return ans;
    }
};
```

