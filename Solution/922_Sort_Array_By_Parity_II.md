## Sort Array By Parity II

#### 奇偶指针：

​		声明奇偶指针，奇指针指向奇数位，偶指针指向偶数位，分别判断是否符合按照奇偶排序的要求，分别指向第一个不符合要求的位置，并将元素交换使之符合要求，然后继续向后判断，直到数组结束。

```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if(A.size() < 2)
            return A;
        int j = 1, o = 0;
        int je, oe;
        if(A.size() % 2 == 0){
            je = A.size()-1;
            oe = A.size()-2;
        }
        else{
            je = A.size()-2;
            oe = A.size()-1;
        }
        while(j < je || o < oe){
            while(j < je && A[j] % 2)
                j += 2;
            while(o < oe && A[o] % 2 == 0)
                o += 2;
            if(A[j] % 2 == 0 && A[o] % 2){
                int temp = A[j];
                A[j] = A[o];
                A[o] = temp;
            }
        }
        if(A[j] % 2 == 0 && A[o] % 2){
            int temp = A[j];
            A[j] = A[o];
            A[o] = temp;
        }
        return A;
    }
};
```

