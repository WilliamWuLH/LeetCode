## Global and Local Inversions

We have some permutation `A` of `[0, 1, ..., N - 1]`, where `N` is the length of `A`.

The number of (global) inversions is the number of `i < j` with `0 <= i < j < N` and `A[i] > A[j]`.

The number of local inversions is the number of `i` with `0 <= i < N` and `A[i] > A[i+1]`.

Return `true` if and only if the number of global inversions is equal to the number of local inversions.

**Example 1:**

```
Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
```

**Example 2:**

```
Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
```

**Note:**

- `A` will be a permutation of `[0, 1, ..., A.length - 1]`.
- `A` will have length in range `[1, 5000]`.
- The time limit for this problem has been reduced.

#### 从后往前维持最小值：

​		根据题目的意思，全局倒置 Global Inversions 的数量和局部倒置 Local Inversions 的数量之所以会存在不同，是因为有一些数 A\[i] > A\[j]，但是 i 和 j 不相邻。

​		换句话说，我们不关心两个相邻的数，反而关心不相邻的数，所以我们可以从后往前维持一个区间的最小值，并且判断这个最小值和在这个区间之前一位的数的大小关系：

- 如果区间的最小值比这个不相邻的数小，说明此时会多出一个全局倒置 Global Inversions，直接返回 false。
- 如果区间最小值不会比这个不相邻的数小，则可以继续移动，不断更新区间，直到遍历整个数组。

最后都没有返回 false，说明全局倒置 Global Inversions 的数量和局部倒置 Local Inversions 的数量相等，返回 true。

```c++
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int l = A.size();
        int min_num = A[l-1];
        for(int i=l-3; i>=0; i--){
            if(A[i] > min_num)
                return false;
            min_num = min(min_num, A[i+1]);
        }
        return true;
    }
};
```

 