## Roman to Integer

#### 人工哈希表 + 前一字符判断：

​		正常顺序：前一个字符的数值是大于等于后一个字符的数值的。

​		如果前一个字符的数值小于后一个字符的数值，需要减去两个前一字符的数值，得到正确值。

```c++
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> hash = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int len = s.length();
        int ans = 0;
        for(int i=0;i<len;i++){
            ans += hash[(char)s[i]];
            if(i > 0 && hash[(char)s[i]] > hash[(char)s[i-1]]){
                ans -= hash[(char)s[i-1]] * 2;
            }
        }
        return ans;
    }
};
```

