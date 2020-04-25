## Plus One

#### 是否进位了：

​		判断加 1 之后是否会进位，进位了就继续计算，不进位就返回。

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i>=0; i--){
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0)
                return digits;
        }
        vector<int> ans = digits;
        ans.insert(ans.begin(), 1);
        return ans;
    }
};
```

