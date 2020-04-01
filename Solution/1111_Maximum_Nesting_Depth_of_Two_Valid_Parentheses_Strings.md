## Maximum Nesting Depth of Two Valid Parentheses Strings

#### 栈 + 奇偶分配：

```c++
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for(auto c : seq){
            if(c == '('){
                d++;
                ans.push_back(d % 2);
            }
            else{
                ans.push_back(d % 2);
                d--;
            }
        }
        return ans;
    }
};
```

