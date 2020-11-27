## Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```

**Note:**

- Each element in the result must be unique.
- The result can be in any order.

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

