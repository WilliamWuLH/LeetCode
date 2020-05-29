## Repeated Substring Pattern

#### 将字符串分割为等长的子字符串 + 判断子字符串是否相等：

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len < 2)
            return false;
        for(int i=2; i<=len; i++){
            if(len % i)
                continue;
            int slen = len / i;
            int pos = 0;
            string first = s.substr(pos, slen);
            while(1){
                pos += slen;
                if(pos == len)
                    break;
                string temp = s.substr(pos, slen);
                if(temp != first)
                    break;
            }
            if(pos == len)
                return true;
        }
        return false;
    }
};
```

