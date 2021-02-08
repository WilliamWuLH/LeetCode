## Longest Turbulent Subarray

Given an integer array `arr`, return *the length of a maximum size turbulent subarray of* `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if and only if:

- For i <= k < j:
  - `arr[k] > arr[k + 1]` when `k` is odd, and
  - `arr[k] < arr[k + 1]` when `k` is even.
- Or, for i <= k < j:
  - `arr[k] > arr[k + 1]` when `k` is even, and
  - `arr[k] < arr[k + 1]` when `k` is odd. 

**Example 1:**

```
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
```

**Example 2:**

```
Input: arr = [4,8,12,16]
Output: 2
```

**Example 3:**

```
Input: arr = [100]
Output: 1
```

**Constraints:**

- `1 <= arr.length <= 4 * 10^4`
- `0 <= arr[i] <= 10^9`

#### 记录相邻元素大小关系 + 线性扫描更新最大长度：

​		首先，我们判断输入的数组是不是只有一个元素，即数组的长度为 1，如果只有一个元素则直接返回 1。

​		接着我们需要记录数组中每个相邻元素的大小关系，以便后续进行扫描判断符合湍流子数组定义的数组长度。假设输入的数组长度为 n，那么就有 n-1 对相邻的元素，我们开辟一个长度为 n-1 的数组 t 用于记录这些相邻元素的大小关系，其中 t[i] 表示 arr[i] 和 arr[i+1] 之间的大小关系：

- 如果 arr[i] == arr[i+1]，则 t[i] = 6 表示相邻元素相等。
- 如果 arr[i] < arr[i+1]，则 t[i] = 1 表示左边的元素小于右边的元素。
- 如果 arr[i] > arr[i+1]，则 t[i] = -1 表示左边的元素大于右边的元素。

​		有了以上的相邻元素大小关系记录，我们就可以很直观的判断哪些子数组是符合湍流子数组的。

​		由于之前已经把输入数组长度为 1 （只有一个元素）的情况进行了讨论，所以能走到这一步的输入数组一定是长度大于等于 2 的，所以至少有一对相邻的元素，所以此时 t[0] 是一定存在的，我们根据 t[0] 进行湍流子数组的长度初始化：

- 如果 t[0] == 6，说明第一对相邻元素是相等的关系，所以此时的湍流子数组长度 cur 为 1。
- 如果 t[0] != 6，说明此时第一对相邻元素不是相等关系，而且在这之前没有其他的大小关系的约束，所以这第一对相邻元素符合湍流子数组，长度 cur 为 2。

​		然后接着线性扫描后续相邻元素的大小关系，并且需要及时更新湍流子数组的最大长度：

- 如果 t[i] == -t[i-1]，说明此时前面的湍流子数组加上后面的这对相邻元素之后仍然符合湍流子数组的定义，所以此时该湍流子数组的长度加一：cur++。
- 如果此时 t[i] != -t[i-1]，说明此时前面的湍流子数组加上后面的这对相邻元素之后不再符合湍流子数组的定义，所以我们此时可以先进行湍流子数组的最大长度更新：ans = max(ans, cur)，然后再根据当前的相邻元素大小关系进行新的湍流子数组的长度初始化，如同之前根据 t[0] 进行长度初始化一样。

最后，完成了对数组 t 的线性扫描之后，返回最大湍流子数组的长度：max(ans, cur)

```c++
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 1;
        vector<int> t(n-1, 6);
        for(int i=0; i<n-1; i++)
            if(arr[i] != arr[i+1])
            t[i] = arr[i] < arr[i+1] ? 1 : -1;
        int cur = 1;
        if(t[0] != 6)
            cur++;
        int ans = cur;
        for(int i=1; i<n-1; i++){
            if(t[i] == -t[i-1])
                cur++;
            else{
                ans = max(ans, cur);
                cur = t[i] == 6 ? 1 : 2;
            }
        }
        return max(ans, cur);
    }
};
```

#### 空间优化：

​		在上述的解法中，我开辟了一个长度为 n-1 的数组 t 用于记录输入数组中相邻元素的大小关系，其实我们仔细阅读解法和代码可以发现，在进行线性扫描判断时，当前的相邻元素大小关系只需要和前一个的相邻元素的关系进行比较，不需要和其他的相邻元素进行讨论，所以我们可以把这个记录所有相邻元素大小关系的数组 t 压缩到只记录当前相邻元素和前一个相邻元素大小关系的常数额外空间。

​		具体代码如下：

```c++
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 1;
        int pre = arr[0] == arr[1] ? 6 : (arr[0] < arr[1] ? 1 : -1);
        int temp = pre == 6 ? 1 : 2;
        int ans = temp;
        for(int i=1; i<n-1; i++){
            int cur = arr[i] == arr[i+1] ? 6 : (arr[i] < arr[i+1] ? 1 : -1);
            if(pre == -cur)
                temp++;
            else{
                ans = max(ans, temp);
                temp = cur == 6 ? 1 : 2;
            }
            pre = cur;
        }
        return max(ans, temp);
    }
};
```

#### 双指针：

​		具体代码如下

```c++
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        int l = 0, r = 0;
        while (r < n - 1) {
            if (l == r) {
                if (arr[l] == arr[l + 1])
                    l++;
                r++;
            }
            else{
                if (arr[r - 1] < arr[r] && arr[r] > arr[r + 1])
                    r++;
                else if (arr[r - 1] > arr[r] && arr[r] < arr[r + 1])
                    r++;
                else
                    l = r;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

