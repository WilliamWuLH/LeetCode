## Permutation Sequence

The set `[1, 2, 3, ..., n]` contains a total of `n!` unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for `n = 3`:

1. `"123"`
2. `"132"`
3. `"213"`
4. `"231"`
5. `"312"`
6. `"321"`

Given `n` and `k`, return the `kth` permutation sequence.

**Example 1:**

```
Input: n = 3, k = 3
Output: "213"
```

**Example 2:**

```
Input: n = 4, k = 9
Output: "2314"
```

**Example 3:**

```
Input: n = 3, k = 1
Output: "123"
```

**Constraints:**

- `1 <= n <= 9`
- `1 <= k <= n!`

#### 依次确定使用第几小的数字：

​		由于排列的顺序是由小到大的，所以可以依次计算出第几个排列在第几个位置应该使用哪个数字。

​		详见代码。

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> num;
        int loop = 1;
        for(int i=1; i<=n; i++){
            num.push_back(i);
            loop *= i;
        }
        loop /= n;
        k -= 1;
        while(num.size() != 0){
            int temp = k / loop;
            ans += to_string(num[temp]);
            num.erase(num.begin()+temp);
            k %= loop;
            n = n > 1 ? n-1 : 1; 
            loop /= n;
        }
        return ans;
    }
};
```

