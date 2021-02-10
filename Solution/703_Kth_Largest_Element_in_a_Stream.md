## Kth Largest Element in a Stream

Design a class to find the `kth` largest element in a stream. Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Implement `KthLargest` class:

- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Returns the element representing the `kth` largest element in the stream.

**Example 1:**

```
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

**Constraints:**

- `1 <= k <= 10^4`
- `0 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.
- It is guaranteed that there will be at least `k` elements in the array when you search for the `kth` element.

#### 排序：

​		直接将初始数组进行排序，并且在每一次的 add 时通过二分查找找到正确的添加位置，并且返回此时排名第 k 大的元素，十分直观。

```c++
class KthLargest {
private:
    vector<int> data;
    int thek;
public:
    KthLargest(int k, vector<int>& nums) {
        thek = k;
        data = nums;
        sort(data.begin(), data.end());
    }
    
    int add(int val) {
        int l=0, r=data.size();
        while(l < r){
            int mid = ((r - l) >> 1) + l;
            if(data[mid] > val)
                r = mid;
            else
                l = mid+1;
        }
        data.insert(data.begin()+l, val);
        return *(data.end()-thek);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

#### 最小堆（小根堆）：

​		我们只需要维护一个最小堆，并且这个最小堆的大小为 k。

​		开始时，我们把初始的数组放入这个最小堆中，然后在后续的 add 的过程中，我们维持这个最小堆的大小为 k，即把那些在初始数组和 add 添加的数字中小于第 k 大元素（所有的数中大小排前 k 大的数）去掉，留下所有的数中大小排前 k 大的数。因为此时的堆是最小堆，所以此时该堆的堆顶元素就是我们要的第 k 大元素。

```c++
class KthLargest {
private:
    priority_queue<int, std::vector<int>, std::greater<int>> data;
    int thek;
public:
    KthLargest(int k, vector<int>& nums) {
        thek = k;
        for(auto &i : nums)
            data.push(i);
    }
    
    int add(int val) {
        data.push(val);
        while(data.size() > thek)
            data.pop();
        return data.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

