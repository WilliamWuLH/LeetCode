## Count Primes

Count the number of prime numbers less than a non-negative number, `n`.

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```
Input: n = 0
Output: 0
```

**Example 3:**

```
Input: n = 1
Output: 0
```

**Constraints:**

- `0 <= n <= 5 * 10^6`

#### 埃拉托斯特尼筛法，简称埃氏筛或爱氏筛：

​		[自行百度吧......](https://baike.baidu.com/item/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95/374984?fr=aladdin)

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

