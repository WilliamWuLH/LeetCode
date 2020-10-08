## Restore IP Addresses

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

