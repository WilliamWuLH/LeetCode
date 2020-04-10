## Reverse Words in a String

#### 保存单词 + 判断：

```c++
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(temp.length() == 0)
                    continue;
                temp += ' ';
                ans = temp + ans;
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        if(temp.length()){
            temp += ' ';
            ans = temp + ans;
        }
        return ans.substr(0, ans.length()-1);
    }
};
```

