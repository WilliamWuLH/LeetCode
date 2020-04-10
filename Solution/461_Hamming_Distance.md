## Hamming Distance

#### 位运算：

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int ans = 0;
        while(num){
            ans += num & 1;
            num >>= 1;
        }
        return ans;
    }
};
```

