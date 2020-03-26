## Longest Substring Without Repeating Characters

#### 动态规划：

判断字符串为空，返回0。

判断字符串不为空：动态规划：局部最优 --> 整体最优

​		从字符串第二个字符开始判断到字符串的最后一个字符。

记录两个数据：

1. 到达该字符时  满足要求的字符串的  最大长度：ans

2. 到达该字符时  以该字符串结尾的  满足要求的字符串的  长度：dp

   （只有加入后面来的字符，才可能使得  满足要求的字符串  更长）

每判断一个字符，比较一次 ans 和 dp 的大小，保证  局部最优。

最后的 ans 便是答案：整体最优。

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int len = s.length();
        int ans = 1,dp = 1,temp = 0;
        for(int i=1;i<len;i++){
            for(temp=0;temp<dp;temp++){
                if(s[i] == s[i-1-temp])
                    break;
            }
            dp = temp+1;
            ans = max(ans,dp);
        }
        return ans;
    }
};
```

#### 滑动窗口：

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0;
        map<char,int> m;
        while(right < s.length()){
            m[ s[right] ]++;
            while(m[ s[right] ] > 1){
                m[ s[left] ]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
```

