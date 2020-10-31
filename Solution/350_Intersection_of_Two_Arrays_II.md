## Intersection of Two Arrays II

#### 排序法：

​		将两个数组进行排序，然后依次比较，相同的就放入答案数组中，不相同的话分情况进行处理。

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(!nums1.size() || !nums2.size())
            return ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size()){
            while(j < nums2.size()){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nums1[i]);
                    break;
                }
                else if(nums1[i] > nums2[j])
                    j++;
                else if(nums1[i] < nums2[j])
                    break;
            }
            if(j >= nums2.size())
                break;
            if(nums1[i] == nums2[j]){
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
        }
        return ans;
    }
};
```

