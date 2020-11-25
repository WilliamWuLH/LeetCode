## Increasing Decreasing String

#### 排序 + 顺序逆序遍历：

​		首先，对字符串进行排序。接下来：

1. **顺序遍历字符串**，把每一个各不相同的字符按顺序从字符串中取出来，并存到答案字符串中，把取出的字符从原字符串中删除。
2. **逆序遍历字符串**，把每一个各不相同的字符按顺序从字符串中取出来，并存到答案字符串中，把取出的字符从原字符串中删除。
3. 如果此时原始字符串中还有字符，说明字符还没有取完，重复 1-2 过程。

最后答案字符串为答案返回。

```c++
class Solution {
public:
    string sortString(string s) {
        string ans = "";
        sort(s.begin(), s.end());
        while(s.length()){
            char cur = s[0]+1;
            for(int i=0; i<s.length(); i++){
                if(s[i] != cur){
                    ans += s[i];
                    cur = s[i];
                    s.erase(s.begin()+i);
                    i--;
                }
            }
            if(s.length() == 0)
                break;
            cur += 1;
            for(int i = s.length()-1; i>=0; i--){
                if(s[i] != cur){
                    ans += s[i];
                    cur = s[i];
                    s.erase(s.begin()+i);
                }
            }
        }
        return ans;
    }
};
```

#### 统计各个字符的个数 + 顺序逆序组合：

​		首先统计字符串中各个字符的个数。

1. 顺序遍历字符表，把此时还有的字符添加到答案字符串中，并把该字符的个数减一。
2. 逆序遍历字符表，把此时还有的字符添加到答案字符串中，并把该字符的个数减一。
3. 判断答案字符串的长度是否和原始字符串的长度相等，如果不相等说明还有字符没有讨论，重复 1-2 步骤。

返回答案字符串。

```c++
class Solution {
public:
    string sortString(string s) {
        int a[26];
        int len = s.length();
        memset(a, 0, sizeof(int)*26);
        for(auto i : s)
            a[i-'a']++;
        s = "";
        while(s.length() < len){
            for(int i=0; i<26; i++){
                if(a[i]){
                    s += 'a'+i;
                    a[i]--;
                }
            }
            for(int i=25; i>=0; i--){
                if(a[i]){
                    s += 'a'+i;
                    a[i]--;
                }
            }
        }
        return s;
    }
};
```

