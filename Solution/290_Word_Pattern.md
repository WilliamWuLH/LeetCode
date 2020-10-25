## Word Pattern

#### 字符串单词提取 + 哈希匹配：

```c++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> the_s;
        map<char, string> hash1;
        map<string, char> hash2;
        split_s(s, the_s);
        if(pattern.size() != the_s.size())
            return false;
        for(int i=0; i<pattern.size(); i++){
            if(hash1.count(pattern[i]) && hash1[pattern[i]] != the_s[i])
                return false;
            if(hash2.count(the_s[i]) && hash2[the_s[i]] != pattern[i])
                return false;
            hash1[pattern[i]] = the_s[i];
            hash2[the_s[i]] = pattern[i];
        }
        return true;
    }
    void split_s(string s, vector<string> &the_s){
        string temp = "";
        for(auto i : s){
            if(i == ' '){
                if(temp.size())
                    the_s.push_back(temp);
                temp = "";
            }
            else
                temp += i;
        }
        if(temp.size())
            the_s.push_back(temp);
        return;
    }
};
```

