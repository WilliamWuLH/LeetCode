## 4Sum II

Given four lists A, B, C, D of integer values, compute how many tuples `(i, j, k, l)` there are such that `A[i] + B[j] + C[k] + D[l]` is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

**Example:**

```
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
```

#### 分组计算 + 哈希存值：

​		首先，将四个数组两两分为一组，所以分出两组。

​		计算 A 和 B 中每个数字相加的情况，使用哈希表记录两个数组中每个数字两两相加结果，并将该结果的次数加一，统计出现各种结果的总次数。

​		接着再计算 C 和 D 中每个数字相加的情况，取 C 和 D 中每个数字两两相加的**结果的负值**作为索引在哈希表中找出现此结果的次数，加入到最后的答案中。

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> A_B;
        int ans = 0;
        for(auto i : A)
            for(auto j : B)
                A_B[i+j]++;
        for(auto i : C)
            for(auto j : D)
                if(A_B.count(-i-j))
                    ans += A_B[-i-j];
        return ans;
    }
};
```

