## Minimum Window Substring

#### 滑动窗口：

​			滑动窗口的思想：**双指针**，左右指针都从 0 开始，右指针负责找到合法的有效区间，左指针负责优化这个合法有效区间。

1. 初始化时左指针 left 和右指针 right 都从 0 开始，left 和 right 夹起来的区间称为一个“窗口”。
2. 右指针 right 向右（向尾部）移动，扩大窗口，并且不断判断区间是否合法（符合题目要求）。
3. 若此时的区间合法（找到了一个符合要求的“窗口”），右指针 right 停止移动，左指针 left 开始向右（向尾部）移动，缩小窗口，并且不断判断区间是否合法（符合题目要求），同时也要更新此时的最优答案。
4. 当此时的区间不合法时（不符合题目要求），左指针 left 停止移动，继续重复上述的第 2 步和第 3 步，直到右指针 right 到达最右边（尾部），算法结束。

##### 重点难点：

- 怎么判断此时的区间是否合法（符合题目的要求）？这一步的处理关乎时间空间复杂度的优化。
- 怎么更新此时的最优答案？

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0,right = 0,match = 0;
        int start = -1,len = INT_MAX;
        map<char,int> m;
        for(auto c : t)
            m[c]++;
        while(right < s.length()){
            if(--m[ s[right] ] >= 0)
                match++;
            right++;
            while(match == t.length()){
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                if(++m[ s[left] ] > 0)
                    match--;
                left++;
            }
        }
        return start == -1 ? "" : s.substr(start,len);
    }
};
```

