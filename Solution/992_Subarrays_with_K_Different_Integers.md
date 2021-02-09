## Subarrays with K Different Integers

Given an array `A` of positive integers, call a (contiguous, not necessarily distinct) subarray of `A` *good* if the number of different integers in that subarray is exactly `K`.

(For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.)

Return the number of good subarrays of `A`. 

**Example 1:**

```
Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
```

**Example 2:**

```
Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
```

**Note:**

1. `1 <= A.length <= 20000`
2. `1 <= A[i] <= A.length`
3. `1 <= K <= A.length`

#### 滑动窗口：

​		我们容易发现，对于任意一个右端点，可能存在一系列左端点与其对应，满足两端点所指区间对应的子数组内恰有 K 个不同整数。因此可能有 O(n^2) 个子数组满足条件。因此无法暴力解决该题。

​		分析这些左端点，我们可以证明：对于任意一个右端点，能够与其对应的左端点们必然相邻。

​		证明非常直观，假设区间 \[ l1 , r \] 和 \[ l2 , r \] 为满足条件的数组（不失一般性，设 l1 ≤ l2 ）。现在我们设存在一个 l 满足 l1 ≤ l ≤ l2，那么区间 \[ l , r \] 作为 \[ l1 , r \] 的子数组，其中的不同整数数量必然不超过 K。同理，区间 \[ l , r \] 作为 \[ l2 , r \] 的父数组，其中的不同整数数量必然不少于 K。那么可知区间 \[ l , r \] 中的不同整数数量即为 K。

​		这样我们就可以用一个区间 \[ l1 , l2 \] 来代表能够与右端点 r 对应的左端点们。

​		同时，我们可以发现：当右端点向右移动时，左端点区间也同样向右移动。因为当我们在原有区间的右侧添加元素时，区间中的不同整数数量不会减少而只会不变或增加，因此我们需要在区间左侧删除一定元素，以保证区间内整数数量仍然为 K。

​		于是我们可以用滑动窗口解决本题，和普通的滑动窗口解法的不同之处在于，我们需要记录两个左指针 l1 与 l2 来表示左端点区间 \[ l1 , l2 )。第一个左指针表示极大的包含 K 个不同整数的区间的左端点，第二个左指针则表示极大的包含 K−1 个不同整数的区间的左端点。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

```c++
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        vector<int> count1(n+1, 0), count2(n+1, 0);
        int l1 = 0, l2 = 0, r = 0, sum1 = 0, sum2 = 0;
        while(r < n){
            if(count1[ A[r] ] == 0)
                sum1++;
            if(count2[ A[r] ] == 0)
                sum2++;
            count1[ A[r] ]++;
            count2[ A[r] ]++;
            while(sum1 > K){
                count1[ A[l1] ]--;
                if(count1[ A[l1] ] == 0)
                    sum1--;
                l1++;
            }
            while(sum2 > K-1){
                count2[ A[l2] ]--;
                if(count2[ A[l2] ] == 0)
                    sum2--;
                l2++;
            }
            ans += l2 - l1;
            r++;
        }
        return ans;
    }
};
```

