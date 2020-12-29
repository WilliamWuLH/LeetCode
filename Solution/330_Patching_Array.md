## Patching Array

Given a sorted positive integer array *nums* and an integer *n*, add/patch elements to the array such that any number in range `[1, n]` inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

**Example 1:**

```
Input: nums = [1,3], n = 6
Output: 1 
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
```

**Example 2:**

```
Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
```

**Example 3:**

```
Input: nums = [1,2,2], n = 5
Output: 0
```

#### 贪心算法：

##### 解题思路：

​		对于正整数 x，如果区间 [1,x−1] 内的所有数字都已经被覆盖，且 x 在数组中，则区间 [1,2x−1] 内的所有数字也都被覆盖。证明如下：

​		对于任意 1 ≤ y < x，y 已经被覆盖，x 在数组中，因此 y+x 也被覆盖，区间 [x+1,2x−1]（即区间 [1,x−1] 内的每个数字加上 x 之后得到的区间）内的所有数字也被覆盖，由此可得区间 [1,2x−1] 内的所有数字都被覆盖。

​		假设数字 x 缺失，则至少需要在数组中补充一个小于或等于 x 的数，才能覆盖到 x，否则无法覆盖到 x。（**为什么？**因为已经覆盖了 [1,x−1]，这个区间中的数任意再加一个小于或等于 x 的数就可以等于 x 了）

​		如果区间 [1,x−1] 内的所有数字都已经被覆盖，则从贪心的角度考虑，补充 x 之后即可覆盖到 x，且满足补充的数字个数最少。在补充 x 之后，区间 [1,2x−1] 内的所有数字都被覆盖，下一个缺失的数字一定不会小于 2x。

​		可以提出一个贪心的方案：每次找到**未被数组 nums 覆盖的最小的整数 x**，在数组中补充 x，然后寻找下一个未被覆盖的最小的整数，重复上述步骤直到区间 [1,n] 中的所有数字都被覆盖。

##### 具体实现：

​		任何时候都应满足区间 [1,x−1] 内的所有数字都被覆盖。

​		令 x 的初始值为 1，数组下标 index 的初始值为 0，则初始状态下区间 [1,x−1] 为空区间，满足区间内的所有数字都被覆盖。进行如下操作：

- 如果 index 在数组 nums 的下标范围内且 nums [ index ] ≤ x，则将 nums [ index ] 的值加给 x，并将 index 的值加 1。

  - **为什么？**

    因为此时区间 [1,x−1] 已经被覆盖，并且 nums [ index ] ≤ x，所以此时可以覆盖的区间扩展到 [1,x+nums [ index ]−1]，所以将 x 更新为 x+nums [ index ]，并且 index+1 讨论数组下一个元素。

  - **PS：为什么 nums [ index ] > x 时就不能扩展覆盖的区间呢？**仔细想想就知道了！

- 否则，x 没有被覆盖，因此需要在数组中补充 x，然后将 x 的值乘以 2。

  - 在数组中补充 x 之后，被覆盖的区间从 [1,x−1] 扩展到 [1,2x−1]，对 x 的值更新（x <<= 1）以后，被覆盖的区间为 [1,x−1]。

- 重复上述操作，直到 x 的值大于 n。

由于任何时候都满足区间 [1,x−1] 内的所有数字都被覆盖，因此上述操作可以保证区间 [1,n] 内的所有数字都被覆盖。

又由于上述操作只在 x 不被覆盖时才在数组中补充 x，如果不补充 x 则 x 无法被覆盖，因此可以保证补充的数字个数最少。如果减少补充的数字个数，则无法覆盖区间 [1,n] 内的所有数字。

参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)

```c++
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        int len = nums.size(), index = 0;
        long long x = 1;
        while(x <= n){
            if(index < len && nums[index] <= x){
                x += nums[index];
                index++;
            }
            else{
                x <<= 1;
                ans++;
            }
        }
        return ans;
    }
};
```

