## Ugly Number II

#### 动态规划：

​		根据丑数的性质，可以根据之前的丑数计算出下一个丑数。

​		通过动态规划计算出下一个丑数（即未出现的最小的丑数）。

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[2000];
        ugly[0] = 1;
        int c2 = 0, c3 = 0, c5 = 0;
        int ans = 1;
        for(int i=1; i<n; i++){
            ans = min(ugly[c2]*2, min(ugly[c3]*3, ugly[c5]*5));
            ugly[i] = ans;
            while(ugly[c2]*2 <= ans)
                c2++;
            while(ugly[c3]*3 <= ans)
                c3++;
            while(ugly[c5]*5 <= ans)
                c5++;
        }
        return ugly[n-1];
    }
};
```

