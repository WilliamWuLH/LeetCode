## Create Maximum Number

Given two arrays of length `m` and `n` with digits `0-9` representing two numbers. Create the maximum number of length `k <= m + n` from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the `k` digits.

**Note:** You should try to optimize your time and space complexity.

**Example 1:**

```
Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
```

**Example 2:**

```
Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
```

**Example 3:**

```
Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
```

#### 单调栈 + 归并：

​		为了找到长度为 k 的最大数，需要从两个数组中分别选出最大的子序列，这两个子序列的长度之和为 k，然后将这两个子序列合并得到最大数。两个子序列的长度最小为 0，最大不能超过 k 且不能超过对应的数组长度。

​		令数组 nums1 的长度为 l1，数组 nums2 的长度为 l2，则需要从数组 nums1 中选出长度为 x 的子序列，以及从数组 nums2 中选出长度为 y 的子序列，其中 x + y = k，且满足 0 ≤ x ≤ l1 和 0 ≤ y ≤ l2。需要遍历所有可能的 x 和 y 的值，对于每一组 x 和 y 的值，得到最大数。在整个过程中维护可以通过拼接得到的最大数。

​		对于每一组 x 和 y 的值，得到最大数的过程分成两步，第一步是分别从两个数组中得到指定长度的最大子序列，第二步是将两个最大子序列合并。

​		第一步可以通过单调栈实现。单调栈满足从栈底到栈顶的元素单调递减，从左到右遍历数组，遍历过程中维护单调栈内的元素，需要保证遍历结束之后单调栈内的元素个数等于指定的最大子序列的长度。遍历结束之后，将从栈底到栈顶的元素依次拼接，即得到最大子序列。

​		第二步需要自定义比较方法。首先比较两个子序列的当前元素，如果两个当前元素不同，则选其中较大的元素作为下一个合并的元素，否则需要比较后面的所有元素才能决定选哪个元素作为下一个合并的元素。

​		单调栈使用数组实现，数组最左侧为栈底。使用数组实现，可以直接从左到右遍历数组得到最大子序列。

**参考：力扣官方题解**

```c++
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        vector<int> ans(k,0);
        int start = max(0, k-l2);
        int end = min(l1, k);
        for(int i=start; i<=end; i++){
            vector<int> maxs1 = maxsubsequence(nums1, i);
            vector<int> maxs2 = maxsubsequence(nums2, k-i);
            vector<int> merge_num = merge(maxs1, maxs2);
            if(compare(ans, merge_num, 0, 0) < 0)
                ans = merge_num;
        }
        return ans;
    }
    vector<int> maxsubsequence(vector<int> &a, int k){
        vector<int> stack(k,0);
        int top = -1;
        int remain = a.size()-k;
        for(auto i : a){
            while(top >= 0 && stack[top] < i && remain > 0){
                top--;
                remain--;
            }
            if(top < k-1)
                stack[++top] = i;
            else
                remain--;
        }
        return stack;
    }
    vector<int> merge(vector<int> &a, vector<int> &b){
        int la = a.size();
        int lb = b.size();
        if(la == 0)
            return b;
        if(lb == 0)
            return a;
        vector<int> ans(la+lb);
        int aindex = 0, bindex = 0;
        for(int i=0; i<la+lb; i++){
            if(compare(a, b, aindex, bindex) > 0)
                ans[i] = a[aindex++];
            else
                ans[i] = b[bindex++];
        }
        return ans;
    }
    int compare(vector<int> &a, vector<int> &b, int na, int nb){
        int la = a.size();
        int lb = b.size();
        while(na < la && nb < lb){
            int diff = a[na] - b[nb];
            if(diff)
                return diff;
            na++;
            nb++;
        }
        return (la-na)-(lb-nb);
    }
};
```

