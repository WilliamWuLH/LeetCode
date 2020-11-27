## Next Permutation

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be **[in place](http://en.wikipedia.org/wiki/In-place_algorithm)** and use only constant extra memory.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,3,2]
```

**Example 2:**

```
Input: nums = [3,2,1]
Output: [1,2,3]
```

**Example 3:**

```
Input: nums = [1,1,5]
Output: [1,5,1]
```

**Example 4:**

```
Input: nums = [1]
Output: [1]
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

#### 找规律：

​		找到下一个按照字典序的排列，所以思路应该是从排列的尾部开始找。

​		首先从排列的尾部往前找，找到第一个 nums[ i-1 ] < nums[ i ] 的位置，此时说明通过将 nums[ i-1 ] 和排列在 nums[ i-1 ] 后面的并且比 nums[ i-1 ] 大的数 nums[ j ] 互换位置，将得到更大的排列。

​		如果找不到 nums[ i-1 ] < nums[ i ] 的位置，则说明此时的排列是最大的，直接将整个排列进行反转，得到最小的排列。

​		若找到 nums[ i-1 ] < nums[ i ] 的位置，此时的任务是找到一个数和 nums[ i-1 ] 进行交换，这个数需要满足：这个数排列在 nums[ i-1 ] 的后面，并且是比 nums[ i-1 ] 大的数中最小的那一个数。

​		完成交换后，由于 nums[ i-1 ] 已经比之前更大了，所以需要将排在 nums[ i-1 ] 后面的数变为最小的排列，即把在 nums[ i-1 ] 后面的排列进行反转。

​		完成交换和反转之后便得到了下一个按照字典序的排列。

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size()-1;
        while(pos > 0 && nums[pos] <= nums[pos-1])
            pos--;        
        reverse(nums.begin()+pos,nums.end());
        if(pos > 0){
            for(int i=pos;i<nums.size();i++){
                if(nums[i] > nums[pos-1]){
                    swap(nums[pos-1],nums[i]);
                    break;
                }
            }
        }
        return;
    }
};
```

