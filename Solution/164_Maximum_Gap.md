## Maximum Gap

#### 直接 sort + 依次对比最大间距：

​		直接把数组原始进行 sort 排序，然后再按照顺序依次两两比较间距，取出最大间距。

```c++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        for(int i=1; i<n; i++)
            ans = max(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
```

#### 桶排序的变形：每个桶只存该桶范围内的最大值和最小值

​		找出数组中的最大值 max_num 和最小值 min_num，数组中的数字个数为 n，分析可知，相邻数字的最大间距不会小于 ⌈ (max_num - min_num) / (n - 1) ⌉ 。为什么是 (n - 1)，仔细想想就知道了。

​		所以，我们定义 n 个桶来装数组中的数。如何确定某个数 i 应该放入哪个桶？计算这个数 i 和最小值 min_num 的间距 d，将 d 除以 (max_num - min_num) / (n - 1) 取模，最后结果在 0 到 n-1 之间，所以可以用 n 个桶存下。

​		在将数字存入桶中的时候我们只需要关心此时桶内的最大值和最小值，因为我们要计算的是桶与桶之间的间距，所以桶内的中间值并不起到作用，只有最小值（和上一个桶比较）和最大值（和下一个桶比较）有用。

​		在计算最大间距时，没有存数字的桶就不计入讨论，因为没有存数字意味着没有数字在这个范围内。所以此时需要一个变量 pre 来存上一个相邻的桶的编号（中间的桶都是空桶，没有数字）。

**重点难点：**

1. 由于数组数字取值范围是整个 int 域，所以计算间距可能超过取值范围，所以使用 long 存间距。
2. 要判断 max_num - min_num 是否为 0，如果为 0 应该提前返回结果，因为 0 不能作为除数。

```c++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n < 2)
            return 0;
        long max_num = *max_element(nums.begin(), nums.end());
        long min_num = *min_element(nums.begin(), nums.end());
        if(max_num == min_num)
            return 0;
        vector<pair<int, int>> bucket(n, pair<int, int>(INT_MAX, INT_MIN));
        for(long i : nums){
            int index = ((i - min_num) * (n - 1))/(max_num - min_num);
            if(i < bucket[index].first)
                bucket[index].first = i;
            if(i > bucket[index].second)
                bucket[index].second = i;
        }
        int pre = -1;
        for(int i=0; i<n; i++){
            if(bucket[i].first == INT_MAX)
                continue;
            if(pre > -1)
                ans = max(ans, bucket[i].first - bucket[pre].second);
            pre = i;
        }
        return ans;
    }
};
```

