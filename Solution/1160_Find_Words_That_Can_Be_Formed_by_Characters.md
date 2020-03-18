## Find Words That Can Be Formed by Characters

#### 建字母表统计字母出现个数：

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count[26];
        int ans = 0;
        for(int i=0;i<26;i++)
            count[i] = 0;
        for(int i=0;i<chars.length();i++){
            count[chars[i]-'a']++;
        }
        vector<string>::iterator iter;
        for(iter=words.begin();iter!=words.end();iter++){
            string s = *iter;
            int i;
            int temp[26];
            for(i=0;i<26;i++)
                temp[i] = count[i];
            for(i=0;i<s.length();i++){
                temp[s[i]-'a']--;
                if(temp[s[i]-'a'] < 0)
                    break;
            }
            if(i < s.length())
                continue;
            else
                ans += s.length();
        }
        return ans;
    }
};
```

