## Subarray Sums Divisible by K

#### 前缀和 + 哈希表 + 同余定理：

```c++
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int, int> record;
        int ans = 0, sum = 0;
        record[0] = 1;
        for(auto i : A){
            sum += i;
            int temp = (sum%K + K) % K;
            if(record.count(temp))
                ans += record[temp];
            record[temp]++;
        }
        return ans;
    }
};
```

