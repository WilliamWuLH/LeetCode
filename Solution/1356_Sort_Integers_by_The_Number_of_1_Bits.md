## Sort Integers by The Number of 1 Bits

#### 直接法：

​		开一个数组存各个数字的二进制下 1 的数目，然后再通过这个数组对原数字数组进行排序即可。

​		重点难点：知道怎么求一个数字在二进制下 1 的数目。还有 sort 函数自定义排序规则（匿名函数）。

```c++
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for(auto i : arr){
            bit[i] = 0;
            int temp = i;
            while(temp){
                bit[i] += temp & 1;
                temp >>= 1;
            }
        }
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if(bit[x] < bit[y])
                return true;
            if(bit[x] > bit[y])
                return false;
            return x < y;
        });
        return arr;
    }
};
```

