## Product of Array Except Self

Given an array `nums` of *n* integers where *n* > 1,  return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

**Example:**

```
Input:  [1,2,3,4]
Output: [24,12,8,6]
```

**Constraint:** It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

**Note:** Please solve it **without division** and in O(*n*).

**Follow up:**
Could you solve it with constant space complexity? (The output array **does not** count as extra space for the purpose of space complexity analysis.)

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

