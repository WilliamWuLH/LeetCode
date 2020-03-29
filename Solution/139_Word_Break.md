## Word Break

#### 深度优先搜索 DFS：

​		时间复杂度太高。

#### 动态规划：

​		相当于把字符串分为两个部分，前面的部分已经计算过是否可以由单词拼接而成，并且已经保存了结果，后面的部分即需要判断的单词，在单词集合里面找是否存在后面整个部分的单词。

​		i 表示现在需要判断的字符串长度（子字符串长度），j 表示现在需要判断的单词的开始位置。

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.length();
        int wsize = wordDict.size();
        int dp[slen+1];
        dp[0] = 1;
        for(int i=1; i<=slen; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                if(dp[j]){
                    string temp = s.substr(j,i-j);
                    if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                        dp[i] = 1;
                        break;                        
                    }
                }
            }
        }
        return dp[slen] == 1;
    }
};
```

