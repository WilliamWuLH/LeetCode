## Restore IP Addresses

Given a string `s` containing only digits, return all possible valid IP addresses that can be obtained from `s`. You can return them in **any** order.

A **valid IP address** consists of exactly four integers, each integer is between `0` and `255`, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are **valid** IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are **invalid** IP addresses. 

**Example 1:**

```
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Example 2:**

```
Input: s = "0000"
Output: ["0.0.0.0"]
```

**Example 3:**

```
Input: s = "1111"
Output: ["1.1.1.1"]
```

**Example 4:**

```
Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
```

**Example 5:**

```
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

**Constraints:**

- `0 <= s.length <= 3000`
- `s` consists of digits only.

#### 暴力：

​		遍历所有合法的 IP。

```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for(int a=1; a<=3; a++){
            for(int b=1; b<=3; b++){
                for(int c=1; c<=3; c++){
                    for(int d=1; d<=3; d++){
                        if(a+b+c+d == s.length()){
                            int na = stoi( s.substr(0, a) );
                            int nb = stoi( s.substr(a, b) );
                            int nc = stoi( s.substr(a+b, c) );
                            int nd = stoi( s.substr(a+b+c, d) );
                            if(na <= 255 && nb <= 255 && nc <= 255 && nd <=255){
                                string ip = to_string(na) + "." + to_string(nb) + "." + to_string(nc) + "." + to_string(nd);
                                if(ip.length() == s.length() + 3)
                                    ans.push_back(ip);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

