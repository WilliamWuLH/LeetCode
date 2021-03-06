## Binary Watch

A binary watch has 4 LEDs on the top which represent the **hours** (**0-11**), and the 6 LEDs on the bottom represent the **minutes** (**0-59**).

Each LED represents a zero or one, with the least significant bit on the right.

Given a non-negative integer *n* which represents the number of LEDs that are currently on, return all possible times the watch could represent.

**Example:**

```
Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
```

**Note:**

- The order of output does not matter.
- The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
- The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

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

