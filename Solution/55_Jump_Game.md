## Jump Game

#### 贪心法：

​				从数组的尾部开始往前找，找到可以到达最后一个位置的，离第一个位置最近的位置。

​				最后判断这个位置是不是数组的第一个位置。

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int pos = len-1;
        for(int i=len-1; i>=0; i--){
            if(i+nums[i] >= pos)
                pos = i;
        }
        return pos == 0;
    }
};
```

