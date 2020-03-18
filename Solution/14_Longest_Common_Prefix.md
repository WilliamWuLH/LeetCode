## Longest Common Prefix  

#### 纵向比较：

​		首先比较全部字符串的第一个字符，然后再比较全部字符串的第二个字符，以此类推，直到出现字符不相同或者字符串结束，得到答案。

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty())
            return ans;
        int size = strs.size();
        int len = strs[0].length();
        for(int i=0;i<len;i++){
            for(int j=1;j<size;j++){
                if(i >= strs[j].length() || strs[0][i] != strs[j][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
```

