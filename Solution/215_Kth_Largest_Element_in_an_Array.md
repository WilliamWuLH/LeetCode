## Kth Largest Element in an Array

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

