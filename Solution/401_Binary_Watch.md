## Binary Watch

#### 遍历 + 判断：

```c++
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i=0; i<12; i++){
            for(int j=0; j<60; j++){
                if(count(i) + count(j) == num)
                    ans.push_back(to_string(i)+":"+(j > 9 ? to_string(j) : "0"+to_string(j)));
            }
        }
        return ans;
    }
    int count(int num){
        int ans = 0;
        while(num){
            ans += num & 1;
            num >>= 1;
        }
        return ans;
    }
};
```

