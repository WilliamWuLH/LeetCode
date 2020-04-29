## Reverse Bits

#### 位运算（左移右移，与运算）：

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int loop = 32;
        while(loop--){
            uint32_t temp = n & 1;
            n >>= 1;
            ans <<= 1;
            ans += temp;
        }
        return ans;
    }
};
```

