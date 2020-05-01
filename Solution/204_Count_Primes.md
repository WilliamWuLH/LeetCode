## Count Primes

#### 埃拉托斯特尼筛法，简称埃氏筛或爱氏筛：

​		自行百度吧......

```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        for(int i=2; i*i<n; i++)
            if(isprime[i])
                for(int j=i*i; j<n; j+=i)
                    isprime[j] = false;
        int ans = 0;
        for(int i=2; i<n; i++)
            if(isprime[i])
                ans++;
        return ans;
    }
};
```

