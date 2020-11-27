## Subarray Sums Divisible by K

Given an array `A` of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by `K`.

**Example 1:**

```
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

**Note:**

1. `1 <= A.length <= 30000`
2. `-10000 <= A[i] <= 10000`
3. `2 <= K <= 10000`

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

