## Shortest Unsorted Continuous Subarray

Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return *the shortest such subarray and output its length*.

**Example 1:**

```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
```

**Example 3:**

```
Input: nums = [1]
Output: 0
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

#### 2021.2.25 再回首：

#### 单调栈：

​		题目给定一个整数数组 nums ，需要找出一个连续子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。我们要找出符合题意的最短子数组，并输出它的长度。

​		转换一下思路，既然要找最短的需要进行升序排序的连续子数组，那么我们也可以在原数组中找到最长的不需要进行升序排序的连续子数组。分析可知，我们需要在原数组的首部和尾部进行寻找，在首部和尾部找到它们各自已经升序的连续子数组，剩下的数组元素就是我们要求的答案。

​		这里可以使用单调栈的思想。单调栈需要考虑的无非就是什么时候需要弹出元素和什么时候需要添加元素。

​		首先讨论什么时候可以添加元素到单调栈？当单调栈中还没有弹出过元素时，我们可以添加数组元素到单调栈中，这是因为我们要保证找到的是连续子数组。如果有元素被弹出单调栈，则说明此时我们再添加元素进单调栈之后会使得数组不连续。

​		什么时候需要弹出元素？

- 对于数组首部，我们找到升序的连续子数组，按照原数组从头到尾遍历数组元素，单调栈中此时应该是升序，就是单调递增的顺序。当单调栈不为空时，当遍历到数组元素比此时的栈顶元素小的时候，就需要弹出当前栈顶元素，并且继续判断新的栈顶和数组元素的大小关系，这是为了找到当前数组元素的正确升序排序位置。

- 对于数组尾部，我们找到降序的连续子数组，因为我们按照原数组从尾到头的顺序遍历数组元素，单调栈中此时应该是降序，就是单调递减的顺序。当单调栈不为空时，当遍历到数组元素比此时的栈顶元素大的时候，就需要弹出当前栈顶元素，并且继续判断新的栈顶和数组元素的大小关系，这是为了找到当前数组元素的正确升序排序位置。

​		在完成数组首部和尾部的单调栈遍历之后，需要记录首部单调栈的大小 l 和尾部单调栈的大小 r 。当 l + r >= n 时，说明原数组已经是升序排序了，没有子数组需要进行升序排序。当 l + r < n 时，说明有子数组需要进行升序排序，并且长度为 n - l - r，这个长度也是符合题意的最短子数组的长度。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), l = 0, r = 0;
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top() > nums[i])
                s.pop();
            if(s.size() == i)
                s.push(nums[i]);
        }
        l = s.size();
        while(!s.empty())
            s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top() < nums[i])
                s.pop();
            if(s.size() == n - 1 - i)
                s.push(nums[i]);
        }
        r = s.size();
        return l + r >= n ? 0 : n - l - r;
    }
};
```

#### 单调栈的优化：只需要开辟常数空间

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = n;
        for(int i=0; i<n; i++){
            while(l >= 0 && nums[l] > nums[i])
                l--;
            if(l == i-1)
                l++;
        }
        for(int i=n-1; i>=0; i--){
            while(r < n && nums[r] < nums[i])
                r++;
            if(r == i+1)
                r--;
        }
        return l >= r ? 0 : r - l - 1;
    }
};
```

#### 排序找不同：

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy;
        copy = nums;
        sort(copy.begin(), copy.end());
        int head = 0, tail = nums.size()-1;
        while(head <= tail && copy[head] == nums[head])
            head++;
        while(head <= tail && copy[tail] == nums[tail])
            tail--;
        return tail-head+1;
    }
};
```

