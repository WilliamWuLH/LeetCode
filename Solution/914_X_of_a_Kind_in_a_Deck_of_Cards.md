## X of a Kind in a Deck of Cards

#### 计数 + 最大公约数：

​			统计各个数字的个数，再求出所有数字的个数的最大公约数，判断是否大于等于 2。

```c++
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> count;
        int len = deck.size();
        for(int i=0; i<len; i++)
            count[ deck[i] ]++;
        int temp = 0;
        map<int,int>::iterator mit;
        for(mit=count.begin(); mit!=count.end(); mit++){
            temp = gcd(mit->second, temp);
        }
        return temp >= 2;
    }
    int gcd(int a, int b){
        return !a ? b : gcd(b%a, a);
    }
};
```

