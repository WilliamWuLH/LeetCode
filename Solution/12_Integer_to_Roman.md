## Integer to Roman 

#### 人工哈希 + 贪心算法：

```c++
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map<int,string> hash;
        hash[1000] = "M";
        hash[900] = "CM";
        hash[500] = "D";
        hash[400] = "CD";
        hash[100] = "C";
        hash[90] = "XC";
        hash[50] = "L";
        hash[40] = "XL";
        hash[10] = "X";
        hash[9] = "IX";
        hash[5] = "V";
        hash[4] = "IV";
        hash[1] = "I";
        map<int,string>::reverse_iterator mit;
        for(mit=hash.rbegin();mit!=hash.rend();){
            if(num >= mit->first){
                ans += mit->second;
                num -= mit->first;
            }
            else
                mit++;
        }
        return ans;
    }
};
```



#### 纯人工哈希：

```c++
class Solution {
public:
    string intToRoman(int num) {
        string c[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        string ans;
        ans += c[3][num / 1000];
        ans += c[2][num / 100 % 10];
        ans += c[1][num / 10 % 10];
        ans += c[0][num % 10];
        return ans;
    }
};
```

