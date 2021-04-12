## Beautiful Arrangement II

Given two integers `n` and `k`, you need to construct a list which contains `n` different positive integers ranging from `1` to `n` and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly `k` distinct integers.

If there are multiple answers, print any of them.

**Example 1:**

```
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
```

**Example 2:**

```
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
```

**Note:**

1. The `n` and `k` are in the range 1 <= k < n <= 10^4.

#### 小数顺序，大数逆序，相间排列：

​		给定两个整数 n 和 k，需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：

① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；

给个例子就能明白什么是**小数顺序，大数逆序，相间排列**：

1 , 1+k , 2 , k , 3 , k-1 , 4 , ...... , 2+k , 3+k, ...... n

- 1 到 1+k 相差 k，1+k 到 2 相差 k-1，2 到 k 相差 k-2，以此类推，可以有相差 k 个不同整数，这其中就是**小数顺序，大数逆序，相间排列**
- 在完成相差 k 个不同整数之后，我们后面的数就直接按照顺序进行排列，这样就可以保证相差有且仅有 k 个不同整数。

具体看代码吧，理解一下！我也想了一下的！

```c++
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n, 1);
        int pos = k+1;
        for(int i=1; i<n; i++){
            if(k){
                if(i % 2)
                    ans[i] = ans[i-1]+k--;
                else
                    ans[i] = ans[i-1]-k--;
            }
            else if(i == pos)
                ans[i] = 1+pos;
            else
                ans[i] = ans[i-1]+1;
        }
        return ans;
    }
};
```

