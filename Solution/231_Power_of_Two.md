## Power of Two

#### 位运算：

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long temp = 1;
        while(temp <= n){
            if(temp == n)
                return true;
            temp <<= 1;
        }
        return false;
    }
};
```

