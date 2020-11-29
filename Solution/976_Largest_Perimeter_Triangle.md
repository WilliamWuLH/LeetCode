## Largest Perimeter Triangle

Given an array `A` of positive lengths, return the largest perimeter of a triangle with **non-zero area**, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return `0`.

**Example 1:**

```
Input: [2,1,2]
Output: 5
```

**Example 2:**

```
Input: [1,2,1]
Output: 0
```

**Example 3:**

```
Input: [3,2,3,4]
Output: 10
```

**Example 4:**

```
Input: [3,6,2,3]
Output: 8
```

**Note:**

1. `3 <= A.length <= 10000`
2. `1 <= A[i] <= 10^6`

#### 排序 + 贪心：

​		首先将数组进行排序，因为我们既然要找三角形的最大周长，就要贪心地找，从最大开始讨论是否符合。

​		因为数组中的每个数字只能用一次（不能重复作为三角形的边，不然就是最大的那个数的等边三角形的周长最大了），所以先讨论数组中最大的三个数能不能构成三角形，如果不能，说明第一大的那个数绝对不可能构成最后的答案（为什么？自己仔细想想？），所以以此类推，看看第二，第三，第四大的数能不能构成三角形，一直讨论到有一组可以构成三角形，这一组就是最大周长的三角形的组成边。

```c++
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i=n-1; i>1; i--){
            if(A[i-1]+A[i-2] > A[i])
                return A[i]+A[i-1]+A[i-2];
        }
        return 0;
    }
};
```

