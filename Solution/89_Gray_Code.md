## Gray Code

#### 了解格雷码的生成过程——异或转换：

​		https://baike.baidu.com/item/%E6%A0%BC%E9%9B%B7%E7%A0%81/6510858?fr=aladdin#5_2

```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i = 0; i < 1<<n; i++)
            ans.push_back(i ^ i >> 1);
        return ans;
    }
};
```

