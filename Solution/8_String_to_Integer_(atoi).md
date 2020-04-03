## String to Integer (atoi)

#### 用 long 保存数据（方便边界判断）：

```c++
class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        long imax = 2147483647, imin = -2147483648;
        int len = str.length();
        int i = 0, flag = 0;
        while(i < len && str[i] == ' ')
            i++;
        if(i < len && (str[i] == '+' || str[i] == '-')){
            if(str[i] == '-')
                flag = 1;
            i++;
        }
        while(i < len){
            if(str[i] < '0' || str[i] > '9')
                break;
            int add = str[i] - '0';
            ans = ans*10 + add;
            if(ans >= imax || -ans <= imin)
                break;
            i++;
        }
        return flag == 0 ? (int)min(ans,imax) : (int)max(-ans,imin);
    }
};
```

