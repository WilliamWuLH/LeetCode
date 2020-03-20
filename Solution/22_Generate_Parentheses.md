## Generate Parentheses

#### 回溯法：

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Back_Tracking("",n,0,ans);
        return ans;
    }
    void Back_Tracking(string now,int front,int behind,vector<string> &ans){
        if(front == 0 && behind == 0){
            if(find(ans.begin(),ans.end(),now) == ans.end())
                ans.push_back(now);
            return;
        }
        if(front > 0){
            now += '(';
            front--;
            behind++;
            Back_Tracking(now,front,behind,ans);
            behind--;
            front++;
            now = now.substr(0,now.length()-1);
        }
        if(behind > 0){
            now += ')';
            behind--;
            Back_Tracking(now,front,behind,ans);
            behind++;
            now = now.substr(0,now.length()-1);
        }
        return;
    }
};
```

#### 优化后的回溯法：

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Back_Tracking("",n,n,ans);
        return ans;
    }
    void Back_Tracking(string now,int front,int behind,vector<string> &ans){
        if(front == 0){
            now.append(behind,')');
            ans.push_back(now);
            return;
        }
        for(int i=front;i>=0;i--){
            string temp = now;
            if(front-i > behind-1)
                return;
            temp.append(i,'(');
            temp.append(1,')');
            Back_Tracking(temp,front-i,behind - 1,ans);
        }
        return;
    }
};
```

