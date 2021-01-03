## Beautiful Arrangement

Suppose you have `n` integers from `1` to `n`. We define a beautiful arrangement as an array that is constructed by these `n` numbers successfully if one of the following is true for the `ith` position (`1 <= i <= n`) in this array:

- The number at the `ith` position is divisible by `i`.
- `i` is divisible by the number at the `ith` position.

Given an integer `n`, return *the number of the beautiful arrangements that you can construct*.

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1, 2]:
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
The second beautiful arrangement is [2, 1]:
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
```

**Example 2:**

```
Input: n = 1
Output: 1
```

**Constraints:**

- `1 <= n <= 15`

#### 回溯法：

​		使用回溯法，遍历每一种情况并进行判断：如果当前数组的元素不符合 “ Beautiful Arrangement ” 的条件则进行剪枝，不再向下回溯。

​		使用 visit 数组记录当前哪一些数字是已经被使用过的。在进行排列时是按照数组位置从小到大依次讨论的，所以当讨论到最后一个位置并且该排列是符合 “ Beautiful Arrangement ” 条件的就 ans++（又多一种排列方式）。

​		这是一种优化的暴力求解，通过回溯法实现更好理解。

```c++
class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        int visit[n];
        memset(visit, 0, sizeof(int)*n);
        backtrack(n, visit, ans, 1);
        return ans;
    }
    void backtrack(int &n, int* visit, int &ans, int pos){
        if(pos > n)
            ans++;
        else{
            for(int i=1; i<=n; i++){
                if(visit[i-1] == 0 && (i % pos == 0 || pos % i == 0)){
                    visit[i-1] = 1;
                    backtrack(n, visit, ans, pos+1);
                    visit[i-1] = 0;
                }
            }
        }
        return;
    }
};
```

