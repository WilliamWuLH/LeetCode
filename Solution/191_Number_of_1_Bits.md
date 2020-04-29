## Number of 1 Bits

#### 位运算（与运算，右移）：

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
```

