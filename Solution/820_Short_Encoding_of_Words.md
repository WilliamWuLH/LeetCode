## Short Encoding of Words

#### 方法一：后缀字典树 Trie

```c++

```



#### 方法二：反转字符串 + 字典序排序

```c++
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        int len = words.size();
        for(int i=0; i<len; i++){
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        for(int i=0; i<len-1; i++){
            if(! words[i+1].find(words[i]))
                continue;    
            ans += words[i].length() + 1;
        }
        ans += words[len-1].length() + 1;
        return ans;
    }
};
```

