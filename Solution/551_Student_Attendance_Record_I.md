## Student Attendance Record I

#### 线性扫描 + 统计个数：

```c++
class Solution {
public:
    bool checkRecord(string s) {
        int count_a = 0, count_l = 0;
        for(auto i : s){
            if(i == 'A' && ++count_a > 1)
                return false;
            if(i == 'L'){
                ++count_l;
                if(count_l > 2)
                    return false;
            }
            else
                count_l = 0;            
        }
        return true;
    }
};
```

