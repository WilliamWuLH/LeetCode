## Product of Array Except Self

#### 乘积 = 左边全部数的乘积 * 右边全部数的乘积：

​		一趟循环，先算出左边全部数的乘积，再一趟循环回来，算出答案。

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int temp = 1;
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                ans.push_back(1);
                continue;
            }
            ans.push_back(ans[i-1]*nums[i-1]);
        }
        for(int i=nums.size()-2; i>=0; i--){
            temp *= nums[i+1];
            ans[i] *= temp;
        }
        return ans;
    }
};
```

