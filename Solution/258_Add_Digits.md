## Add Digits

#### 递归 + 各位相加：

```c++
class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        int ans = 0;
        while(num){
            ans += num % 10;
            num /= 10;
        }
        return addDigits(ans);
    }
};
```

