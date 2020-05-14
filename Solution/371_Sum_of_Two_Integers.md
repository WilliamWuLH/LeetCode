## Sum of Two Integers

#### 全加器——位运算：

​		半加器：a ^= b 计算出没有进位的两整数之和

​		全加器：(a & b) << 1 计算出两整数相加之后产生的进位

​		若一直有进位则不断循环，直到不产生进位则求两整数之和结束。

```c++
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            unsigned long carry = (unsigned long)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```

