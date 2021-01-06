## Kth Missing Positive Number

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

*Find the* `kth` *positive integer that is missing from this array.*

**Example 1:**

```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

**Example 2:**

```
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
```

**Constraints:**

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

#### 利用 arr[i] 与其下标 i 关系：

​		不难发现，一个不缺失元素的序列，会有 arr[i] = i + 1 这样的关系，而在缺失元素之后，会有 arr[i] > i + 1，简单移项可得 arr[i] - i - 1 > 0，缺失一个的时候，相差 1，两个则相差 2，以此类推，缺失越多，两者差距越大，我们要找第 k 个缺失的，换言之，只要 arr[i] - i - 1 == k，我们便找到了题目要找的数字。

参考：[多种解法：暴力筛除、线性搜索、二分查找](https://leetcode-cn.com/problems/kth-missing-positive-number/solution/duo-chong-jie-fa-by-dao-chang-3/)

```c++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i, n = arr.size();
        for(i=0; i<n; i++)
            if(arr[i] - i - 1 >= k)
                return i + k;
        return i + k;
    }
};
```

#### 二分查找：

​		上述的解法没有用上题目给出的条件 严格升序排列，已经找出了 arr[i] - i - 1 > 0 的关系之后，我们可以利用上述的线性查找的方式改为二分查找的方式。

参考：[多种解法：暴力筛除、线性搜索、二分查找](https://leetcode-cn.com/problems/kth-missing-positive-number/solution/duo-chong-jie-fa-by-dao-chang-3/)

```c++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        while(l < r){
            int mid = l + ((r-l) >> 1);
            if(arr[mid] - mid - 1 >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l + k;
    }
};
```

