## Arithmetic Slices

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```

The following sequence is not arithmetic.

```
1, 1, 2, 5, 7
```

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

**Example:**

```
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
```

#### 参考：

- [力扣 (LeetCode)](https://leetcode-cn.com/u/leetcode/)
- [题解](https://leetcode-cn.com/problems/arithmetic-slices/solution/deng-chai-shu-lie-hua-fen-by-leetcode/)

#### 暴力：已优化

​		如果当前在处理一个区间 ( s , e )，其中 A \[ s \]（区间头）和 A \[ e \] （区间尾），我们需要检查这个区间内所有相邻元素的差值是不是都相等。现在，把这个区间扩大一点，变成从 s 到 e + 1，我们就需要再一次对于区间 s : ​e 中的所有元素做一遍等差判断，然后再额外判断 A \[ e + 1 \] 和 A \[ e \] 的差值是不是跟之前的相等。其实是可以不用重复的判断区间 s : ​e 的，只需要判断最后一对元素的差值是不是跟之前区间中的差值相等就可以了。（固定 s，不断增加 e)。

​		需要注意的是，一旦当前区间不满足等差数列了，那就不需要继续判断了。

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        int n = A.size();
        for(int i=0; i<n-2; i++){
            int d = A[i+1] - A[i];
            for(int j=i+2; j<n; j++){
                if(A[j] - A[j-1] == d)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};
```

#### 递归：

​		如果区间 ( i , j ) 是等差数列，那么当 A \[ j + 1 \] 和 A \[ j \] 的差值和之前的差值相等的情况下，区间 ( i , j + 1 ) 也构成一个等差数列。此外，如果区间 ( i , j ) 就不是一个等差数列，那么之后再向右拓展也不可能是一个等差数列了。

​		根据这个规律，我们可以设计一个递归算法。首先，定义变量 ans 来记录数组 A 中所有等差数列的个数。接着，定义一个递归方法 slice(A , i , ans) 来求在区间 ( k , i ) 中，而不在区间 ( k , j ) 中等差数列的个数，其中 j < i。每次递归也都会更新 ans 值。

​		现在，假设我们知道了 slice(A , i−1 , ans) 的值为 x，同时这个区间内元素用 \[ a0 , a1 , a2 , ... a ( i−1 ) \] 来表示。如果这个区间本身就是一个等差数列，这么这里面所有相邻元素之间的差值都是相等的。现在要加入一个新的元素 ai 将区间拓展成 ( 0 , i )，如果拓展之后的区间还是一个等差数列，那么一定存在 ai - a(i-1) = a(i-1) - a(i-2)。因此每加入一个新元素，就会多出 cur 个等差序列。其中新增等差数列的区间为 (0,i), (1,i), ... (i-2,i)，这些区间总数为 x+1。这是因为除了区间 ( 0 , i ) 以外，其余的区间如 (1,i), (2,i), ... (i−2,i) 这些都可以对应到之前的区间 (0,i-1), (1,i-1), ... (i-3,i-1) 上去，其值为 x。

​		因此，每次调用 slice，如果第 i 个元素与前一个元素的差值正好等于之前的差值，我们直接就可以算出新增的等差数组的个数 cur，同时可以更新 ans。但是，如果新元素跟前一个元素的差值不等于之前的差值，也就不会增加等差数列的个数。

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        slice(A, A.size()-1, ans);
        return ans;
    }
    int slice(vector<int>& A, int i, int &ans){
        if(i < 2)
            return 0;
        int cur = 0;
        if(A[i] - A[i-1] == A[i-1] - A[i-2]){
            cur = 1 + slice(A, i-1, ans);
            ans += cur;
        }
        else
            slice(A, i-1, ans);
        return cur;
    }
};
```

#### 动态规划：

​		在上一个方法中，我们开始是从最大区间 ( 0 , n−1 ) 开始的，其中 n 为数组 A 中元素的个数。我们可以观察到区间 ( 0 , i ) 中等差数列的个数只和这个区间中的元素有关。因此，这个问题可以用动态规划来解决。

​		首先创建一个大小为 n 的一维数组 dp。dp \[ i \] 用来存储在区间 ( k , i )， 而不在区间 ( k , j ) 中等差数列的个数，其中 j < i。

​		与递归方法中后向推导不同，我们前向推导 dp 中的值。其余的思路跟上一个方法几乎一样。对于第 i 个元素，判断这个元素跟前一个元素的差值是否和等差数列中的差值相等。如果相等，那么新区间中等差数列的个数即为 1 + dp \[ i−1 \]。ans 同时也要加上这个值来更新全局的等差数列总数。

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), ans = 0;
        vector<int> dp(n, 0);
        for(int i=2; i<n; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp[i] = 1 + dp[i-1];
                ans += dp[i];
            }
        }
        return ans;
    }
};
```

#### 常数空间动态规划：

​		可以观察到我们其实只需要 dp \[ i−1 \] 来决定 dp \[ i \] 的值。因此，相对于整个 dp 数组，我们只需要保存一个最近一个 dp 值就可以了。

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), ans = 0, dp = 0;
        for(int i=2; i<n; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp++;
                ans += dp;
            }
            else
                dp = 0;
        }
        return ans;
    }
};
```

#### 