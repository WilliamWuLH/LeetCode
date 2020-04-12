## Daily Temperatures

#### 栈：

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        int len = T.size();
        vector<int> ans(len, 0);
        for(int i=0; i<len; i++){
            while(!s.empty()){
                if(T[i] <= s.top().second)
                    break;
                ans[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push(make_pair(i, T[i]));
        }
        return ans;
    }
};
```

