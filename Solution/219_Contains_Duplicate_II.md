## Contains Duplicate II

#### 直接法（超时）：

​		直接按顺序判断，判断过的不再判断，复杂度应该是O(n^2)。

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        vector<int> had_handle;
        for(int i=0; i<nums.size(); i++){
            if(find(had_handle.begin(), had_handle.end(), nums[i]) == had_handle.end()){
                had_handle.push_back(nums[i]);
                int p = i;
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[p] == nums[j]){
                        if(j - p <= k){
                            ans = true;
                            return ans;                            
                        }
                        else
                            p = j;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### 散列表：

​		详见代码。

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> access;
        for(int i=0; i<nums.size(); i++){
            if(access.count(nums[i]))
                return true;
            access.insert(nums[i]);
            if(access.size() > k)
                access.erase(nums[i-k]);
        }
        return false;
    }
};
```

