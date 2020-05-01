## Contains Duplicate

#### 使用数据结构 set：

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> temp;
        for(auto i : nums){
            if(temp.count(i))
                return true;
            else
                temp.insert(i);
        }
        return false;
    }
};
```

