## Container With Most Water 

#### 双指针法：

​		**高度低的指针**必须向着**高度高的指针**的方向靠拢：通过高度弥补宽度的减小。

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator left,right;
        int ans = 0;
        int len = height.size() - 1;
        left = height.begin();
        right = height.end();
        right--;
        while(left != right){
            if(*left > *right){
                if(ans < len * *(right)){
                    ans = len * *(right);
                }
                right--;
            }
            else{
                if(ans < len * *(left)){
                    ans = len * *(left);
                }
                left++;
            }
            len--;
        }
        return ans;
    }
};
```

