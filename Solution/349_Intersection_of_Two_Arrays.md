## Intersection of Two Arrays

#### 记录 + 判断 + 删除：

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count;
        vector<int> ans;
        for(auto i : nums1)
            count[i]++;
        for(auto i : nums2){
            if(count.count(i)){
                ans.push_back(i);
                count.erase(i);
            }
        }
        return ans;
    }
};
```

