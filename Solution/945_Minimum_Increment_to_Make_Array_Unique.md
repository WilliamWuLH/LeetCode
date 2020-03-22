## Minimum Increment to Make Array Unique

#### 计数 + 排序：

```c++
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int,int> count;
        int ans = 0;
        int len = A.size();
        for(int i=0; i<len; i++){
            count[A[i]]++;
        }
        map<int,int>::iterator mit;
        for(mit=count.begin(); ; mit++){
            if(mit == count.end()){
                int temp = mit->second - 1;
                ans += (1 + temp) * temp * 0.5;
                break;
            }
            int num = mit->first;
            if(count[num] > 1){
                int temp = mit->second - 1;
                count[num+1] += temp;
                ans += temp;
            }
        }
        return ans;
    }
};
```

