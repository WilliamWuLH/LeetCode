## Single Number

#### 先加后减：

​			出现一次就加上，再出现一次就减去，最后剩下的就是 Single Number。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        map<int, int> m;
        for(int i=0; i<len; i++){
            if(m[ nums[i] ] == 0){
                m[ nums[i] ] = 1;
                ans += nums[i];
            }
            else
                ans -= nums[i];
        }
        return ans;
    }
};
```

#### 位运算：

​			异或：a ^ 0 = a，a ^ a = 0

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i=0; i<len; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
```

