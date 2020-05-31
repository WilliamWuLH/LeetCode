## Kids With the Greatest Number of Candies

#### 找最大值 + 判断：

```c++
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxcandies = 0;
        for(auto i : candies)
            maxcandies = max(maxcandies, i);
        for(auto i : candies){
            if(i + extraCandies >= maxcandies)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
```

