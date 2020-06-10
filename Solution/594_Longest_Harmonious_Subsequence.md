## Longest Harmonious Subsequence

#### 计数：

```c++
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int, int> m;
        for(auto i : nums)
            m[i]++;
        map<int, int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            if(m.count(it->first + 1))
                ans = max(ans, it->second + m[it->first + 1]);
        }
        return ans;
    }
};
```

