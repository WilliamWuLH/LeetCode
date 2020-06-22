## Count and Say

#### 逐层讨论 + 字符串处理：

```c++
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            string temp = "";
            int count = 1;
            for(int j=1; j<ans.length(); j++){
                if(ans[j] == ans[j-1])
                    count++;
                else{
                    temp += to_string(count) + ans[j-1];
                    count = 1;
                }
            }
            temp += to_string(count) + ans[ans.length()-1];
            ans = temp;
        }
        return ans;
    }
};
```

