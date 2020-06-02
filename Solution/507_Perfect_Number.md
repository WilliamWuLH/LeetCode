## Perfect Number

#### 求出所有正因数 + 判断：

```c++
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        int i = 1;
        while(i*i <= num){
            if(num % i == 0){
                sum += i;
                if(i*i != num && i != 1)
                    sum += num / i;
            }
            i++;
        }
        return sum == num && num != 0 && num != 1;
    }
};
```

