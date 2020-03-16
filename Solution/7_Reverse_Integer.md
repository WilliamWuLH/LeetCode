## Reverse Integer

#### 判断32位int型的整数边界：

```c++
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int temp = x % 10;
            x /= 10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;
            ans = ans * 10 + temp;
        }
        return ans;
    }
};
```

