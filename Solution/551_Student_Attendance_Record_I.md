## Student Attendance Record I

You are given a string representing an attendance record for a student. The record only contains the following three characters:

1. **'A'** : Absent.
2. **'L'** : Late.
3. **'P'** : Present.

A student could be rewarded if his attendance record doesn't contain **more than one 'A' (absent)** or **more than two continuous 'L' (late)**.

You need to return whether the student could be rewarded according to his attendance record.

**Example 1:**

```
Input: "PPALLP"
Output: True
```

**Example 2:**

```
Input: "PPALLL"
Output: False
```

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

