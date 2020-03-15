##  Median of Two Sorted Arrays 

#### 二分法：

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 > len2)
            return findMedianSortedArrays(nums2,nums1);
        int mid = (len1 + len2 + 1)/2;
        int min1 = 0, max1 = len1,i,j;
        while(min1 <= max1){
            i = (min1 + max1)/2;
            j = mid - i;
            if(i < len1 && nums1[i] < nums2[j-1])
                min1 = i+1;
            else if(i > 0 && nums1[i-1] > nums2[j])
                max1 = i-1;
            else{
                double max_of_left = max(i > 0 ? nums1[i-1]: INT_MIN, 
                                         j > 0 ? nums2[j-1]: INT_MIN);
                if((len1 + len2) & 1)
                    return max_of_left;
                double min_of_right = min(i < len1 ? nums1[i]: INT_MAX, 
                                          j < len2 ? nums2[j]: INT_MAX);
                return 0.5 * (max_of_left + min_of_right);
            }
        }
        return -1;
    }
};
```

