## Sort Colors

Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers `0`, `1`, and `2` to represent the color red, white, and blue respectively.

**Follow up:**

- Could you solve this problem without using the library's sort function?
- Could you come up with a one-pass algorithm using only `O(1)` constant space?

**Example 1:**

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**

```
Input: nums = [2,0,1]
Output: [0,1,2]
```

**Example 3:**

```
Input: nums = [0]
Output: [0]
```

**Example 4:**

```
Input: nums = [1]
Output: [1]
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is `0`, `1`, or `2`.

#### 统计颜色个数 + 重新排列：

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0,0,0};
        int len = nums.size();
        for(int i=0; i<len; i++){
            count[nums[i]]++;
        }
        int temp = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<count[i]; j++){
                nums[temp] = i;
                temp++;                           
            }
        }
    }
};
```

#### 三指针：

​			一个指针指向 0 的尾部，一个指针指向 2 的开头，一个指针进行遍历。

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len-1, curr = 0;
        while(curr <= right){
            if(nums[curr] == 0)
                swap(nums[curr++], nums[left++]);
            else if(nums[curr] == 2)
                swap(nums[curr], nums[right--]);
            else
                curr++;
        }
    }
};
```

