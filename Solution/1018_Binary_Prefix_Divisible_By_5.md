## Binary Prefix Divisible By 5

Given an array `A` of `0`s and `1`s, consider `N_i`: the i-th subarray from `A[0]` to `A[i]` interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans `answer`, where `answer[i]` is `true` if and only if `N_i` is divisible by 5.

**Example 1:**

```
Input: [0,1,1]
Output: [true,false,false]
Explanation: 
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
```

**Example 2:**

```
Input: [1,1,1]
Output: [false,false,false]
```

**Example 3:**

```
Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]
```

**Example 4:**

```
Input: [1,1,1,0,1]
Output: [false,false,false,false,false]
```

**Note:**

1. `1 <= A.length <= 30000`
2. `A[i]` is `0` or `1`

#### 遍历判断 + 位运算 + 仅保留数字的个位：

​		首先，题目所给的数组所保存的是若干个 0 和 1，所以数组的子数组是要被解释为二进制数的，这里我们就需要通过遍历数组和位运算把数组中的 0 和 1 转化为我们所可以用来运算和判断的 int 型。

​		由于数组的规模很大（30000），所以保存整个数组的二进制数是不可能的，好在我们只需要判断这个数它是否可以被 5 整除，换言之，我们只需要考虑这个数的个位是否可以被 5 整除，因为十位以上的都可以被 5 整除。

​		所以我们只需要保留这个数的个位，并且判断个位即可。

```c++
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int cur = 0;
        for(auto &i : A){
            cur = (cur << 1) + i;
            ans.emplace_back(cur % 5 == 0);
            cur %= 10;
        }
        return ans;
    }
};
```

