## Queue Reconstruction by Height

#### 贪心算法：

​		递归进行：

- 将最高的人按照 k 值升序排序，然后将它们放置到输出队列中与 k 值相等的索引位置上。
- 按降序取下一个高度，同样按 k 值对该身高的人升序排序，然后逐个插入到输出队列中与 k 值相等的索引位置上。
- 直到完成为止。

```c++
class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.begin() + people.size(), compare);
        for(auto i : people)
            ans.insert(ans.begin()+i[1], i);
        return ans;
    }
};
```

