## Sliding Window Median

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:

```
[2,3,4]` , the median is `3
[2,3]`, the median is `(2 + 3) / 2 = 2.5
```

Given an array *nums*, there is a sliding window of size *k* which is moving from the very left of the array to the very right. You can only see the *k* numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given *nums* = `[1,3,-1,-3,5,3,6,7]`, and *k* = 3.

```
Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
```

Therefore, return the median sliding window as `[1,-1,-1,3,5,6]`.

**Note:**
You may assume `k` is always valid, ie: `k` is always smaller than input array's size for non-empty array.
Answers within `10^-5` of the actual value will be accepted as correct.

#### 2021.2.3：Hard 题，全抄的 LeetCode 题解

#### 滑动窗口中位数：双优先队列 + 延迟删除

我们首先思考一下完成本题需要做哪些事情：

​		初始时，我们需要将数组 nums 中的前 k 个元素放入一个滑动窗口，并且求出它们的中位数；

​		随后滑动窗口会向右进行移动。每一次移动后，会将一个新的元素放入滑动窗口，并且将一个旧的元素移出滑动窗口，最后再求出它们的中位数。

​		因此，我们需要设计一个「数据结构」，用来维护滑动窗口，并且需要提供如下的三个接口：

- insert(num)：将一个数 num 加入数据结构；

- erase(num)：将一个数 num 移出数据结构；

- getMedian()：返回当前数据结构中所有数的中位数。

**思路与算法**

​		我们可以使用两个优先队列（堆）维护所有的元素，第一个优先队列 small 是一个大根堆，它负责维护所有元素中较小的那一半；第二个优先队列 large 是一个小根堆，它负责维护所有元素中较大的那一半。具体地，如果当前需要维护的元素个数为 x，那么 small 中维护了 ⌈ x / 2 ⌉ 个元素，large 中维护了 ⌊ x / 2 ⌋ 个元素，其中 ⌈ y ⌉ 和 ⌊ y ⌋ 分别表示将 y 向上取整和向下取整。也就是说：

​		small 中的元素个数要么与 large 中的元素个数相同，要么比 large 中的元素个数恰好多 1 个。

​		这样设计的好处在于：当二者包含的元素个数相同时，它们各自的堆顶元素的平均值即为中位数；而当 small 包含的元素多了一个时，small 的堆顶元素即为中位数。这样 getMedian() 就设计完成了。

​		而对于 insert(num) 而言，如果当前两个优先队列都为空，那么根据元素个数的要求，我们必须将这个元素加入 small；如果 small 非空（显然不会存在 small 空而 large 非空的情况），我们就可以将 num 与 small 的堆顶元素 top 比较：

- 如果 num ≤ top，我们就将其加入 small 中；

- 如果 num > top，我们就将其加入 large 中。

​		在成功地加入元素 num 之后，两个优先队列的元素个数可能会变得不符合要求。由于我们只加入了一个元素，那么不符合要求的情况只能是下面的二者之一：

- small 比 large 的元素个数多了 2 个；

- small 比 large 的元素个数少了 1 个。

​		对于第一种情况，我们将 small 的堆顶元素放入 large；对于第二种情况，我们将 large 的堆顶元素放入 small，这样就可以解决问题了，insert(num) 也就设计完成了。

​		然而对于 erase(num) 而言，设计起来就不是那么容易了，因为我们知道，优先队列是不支持移出非堆顶元素这一操作的，因此我们可以考虑使用「延迟删除」的技巧，即：

​		当我们需要移出优先队列中的某个元素时，我们只将这个删除操作「记录」下来，而不去真的删除这个元素。当这个元素出现在 small 或者 large 的堆顶时，我们再去将其移出对应的优先队列。

​		「延迟删除」使用到的辅助数据结构一般为哈希表 delayed，其中的每个键值对 (num, freq)，表示元素 num 还需要被删除 freq 次。

​		「优先队列 + 延迟删除」有非常多种设计方式，体现在「延迟删除」的时机选择。在本题解中，我们使用一种比较容易编写代码的设计方式，即：

​		我们保证在任意操作 insert(num)，erase(num)，getMedian() 完成之后（或者说任意操作开始之前），small 和 large 的堆顶元素都是不需要被「延迟删除」的。这样设计的好处在于：我们无需更改 getMedian() 的设计，只需要略加修改 insert(num) 即可。

​		我们首先设计一个辅助函数 prune(heap)，它的作用很简单，就是对 heap 这个优先队列（small 或者 large 之一），不断地弹出其需要被删除的堆顶元素，并且减少 delayed 中对应项的值。在 prune(heap) 完成之后，我们就可以保证 heap 的堆顶元素是不需要被「延迟删除」的。

​		这样我们就可以在 prune(heap) 的基础上设计另一个辅助函数 makeBalance()，它的作用即为调整 small 和 large 中的元素个数，使得二者的元素个数满足要求。由于有了 erase(num) 以及「延迟删除」，我们在将一个优先队列的堆顶元素放入另一个优先队列时，第一个优先队列的堆顶元素可能是需要删除的。因此我们就可以用 makeBalance() 将 prune(heap) 封装起来，它的逻辑如下：

- 如果 small 和 large 中的元素个数满足要求，则不进行任何操作；

- 如果 small 比 large 的元素个数多了 2 个，那么我们我们将 small 的堆顶元素放入 large。此时 small 的对应元素可能是需要删除的，因此我们调用 prune(small)；

- 如果 small 比 large 的元素个数少了 1 个，那么我们将 large 的堆顶元素放入 small。此时 large 的对应的元素可能是需要删除的，因此我们调用 prune(large)。

​		此时，我们只需要在原先 insert(num) 的设计的最后加上一步 makeBalance() 即可。然而对于 erase(num)，我们还是需要进行一些思考的：

​		如果 num 与 small 和 large 的堆顶元素都不相同，那么 num 是需要被「延迟删除」的，我们将其在哈希表中的值增加 1；

​		否则，例如 num 与 small 的堆顶元素相同，那么该元素是可以理解被删除的。虽然我们没有实现「立即删除」这个辅助函数，但只要我们将 num 在哈希表中的值增加 1，并且调用「延迟删除」的辅助函数 prune(small)，那么就相当于实现了「立即删除」的功能。

​		无论是「立即删除」还是「延迟删除」，其中一个优先队列中的元素个数发生了变化（减少了 1），因此我们还需要用 makeBalance() 调整元素的个数。

​		此时，所有的接口都已经设计完成了。由于 insert(num) 和 erase(num) 的最后一步都是 makeBalance()，而 makeBalance() 的最后一步是 prune(heap)，因此我们就保证了任意操作完成之后，small 和 large 的堆顶元素都是不需要被「延迟删除」的。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

```c++
class DualHeap {
private:
    // 大根堆，维护较小的一半元素
    priority_queue<int> small;
    // 小根堆，维护较大的一半元素
    priority_queue<int, vector<int>, greater<int>> large;
    // 哈希表，记录「延迟删除」的元素，key 为元素，value 为需要删除的次数
    unordered_map<int, int> delayed;

    int k;
    // small 和 large 当前包含的元素个数，需要扣除被「延迟删除」的元素
    int smallSize, largeSize;

public:
    DualHeap(int _k): k(_k), smallSize(0), largeSize(0) {}

private:
    // 不断地弹出 heap 的堆顶元素，并且更新哈希表
    template<typename T>
    void prune(T& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                --delayed[num];
                if (!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            }
            else {
                break;
            }
        }
    }

    // 调整 small 和 large 中的元素个数，使得二者的元素个数满足要求
    void makeBalance() {
        if (smallSize > largeSize + 1) {
            // small 比 large 元素多 2 个
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            // small 堆顶元素被移除，需要进行 prune
            prune(small);
        }
        else if (smallSize < largeSize) {
            // large 比 small 元素多 1 个
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            // large 堆顶元素被移除，需要进行 prune
            prune(large);
        }
    }

public:
    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        }
        else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        }
        else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    double getMedian() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualHeap dh(k);
        for (int i = 0; i < k; ++i) {
            dh.insert(nums[i]);
        }
        vector<double> ans = {dh.getMedian()};
        for (int i = k; i < nums.size(); ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.push_back(dh.getMedian());
        }
        return ans;
    }
};
```

