## Find All Anagrams in a String

#### 统计字母个数 + 移动窗口：

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int scount[26], pcount[26];
        int plen = p.length(), slen = s.length(), pos = 0;
        if(plen > slen)
            return ans;
        memset(scount, 0, sizeof(scount));
        memset(pcount, 0, sizeof(pcount));
        for(int i=0; i<plen; i++){
            pcount[ p[i]-'a' ]++;
        }
        while(pos < slen){
            if(pos < plen)
                scount[ s[pos]-'a' ]++;
            else{
                scount[ s[pos]-'a' ]++;
                scount[ s[pos-plen]-'a' ]--;
            }
            if(comp(scount, pcount))
                ans.push_back(pos-plen+1);
            pos++;
        }
        return ans;
    }
    bool comp(int a[], int b[]){
        for(int i=0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
```

