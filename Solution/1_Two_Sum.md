## Two Sum

#### 一次哈希：

​		将数值作为索引，在哈希表中找此时数值对应的另一个数值，若存在则取出该数值的编号，若不存在则将此时的数值和它的编号存入哈希表，以供后面使用。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans;
        int len = nums.size();
        for(int i=0;i<len;i++){
            int n = target - nums[i];
            if(m.find(n) != m.end()){
                ans.push_back(m[n]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
```

