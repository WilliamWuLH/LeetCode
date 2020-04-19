## Longest Consecutive Sequence

#### 哈希表 + 判断：

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> hash;
        int ans = 0;
        for(auto i : nums)
            hash[i] = 1;
        for(auto i : hash){
            if(! hash.count(i.first - 1)){
                int cur = 1;
                int thenum = i.first + 1;
                while(hash.count(thenum)){
                    cur++;
                    thenum++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
```

