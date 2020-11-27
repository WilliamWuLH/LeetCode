## Kth Largest Element in an Array

Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

**Example 2:**

```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```

**Note:**
You may assume k is always valid, 1 ≤ k ≤ array's length.

#### 直接 sort：

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return *(nums.end()-k);
    }
};
```

#### 堆排序：

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return heapsort(nums, k);
    }
    void buildheap(vector<int>& nums,int root, int len){
        int child = root*2+1;
        if(child >= len)
            return;
        if(child+1 < len && nums[child+1] > nums[child])
            child++;
        if(nums[root] >= nums[child] )
            return;
        else{
            swap(nums[root], nums[child]);
            buildheap(nums, child, len);
        }
        return;
    }
    int heapsort(vector<int>& nums, int k){
        int len = nums.size();
        for(int i=len/2-1; i>=0; i--)
            buildheap(nums, i, len);
        for(int i=1; i<=k; i++){
            swap(nums[0], nums[len-i]);
            buildheap(nums, 0, len-i);
        }
        return nums[len-k];
    }
};
```

