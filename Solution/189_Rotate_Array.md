## Rotate Array

#### 方法一：

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size())
            return;
        k = k % nums.size();
        for(int i=0; i<k; i++){
            nums.emplace(nums.begin(), *(nums.end()-1));
            nums.pop_back();
        }
    }
};
```

#### 方法二：

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size())
            return;
        k = nums.size() - (k % nums.size());
        vector<int> head(nums.begin(), nums.begin()+k);
        vector<int> tail(nums.begin()+k, nums.end());
        nums = tail;
        nums.insert(nums.end(), head.begin(), head.end());
    }
};
```

