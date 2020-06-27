## Permutation Sequence

#### 依次确定使用第几小的数字：

​		由于排列的顺序是由小到大的，所以可以依次计算出第几个排列在第几个位置应该使用哪个数字。

​		详见代码。

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> num;
        int loop = 1;
        for(int i=1; i<=n; i++){
            num.push_back(i);
            loop *= i;
        }
        loop /= n;
        k -= 1;
        while(num.size() != 0){
            int temp = k / loop;
            ans += to_string(num[temp]);
            num.erase(num.begin()+temp);
            k %= loop;
            n = n > 1 ? n-1 : 1; 
            loop /= n;
        }
        return ans;
    }
};
```

