##  Median of Two Sorted Arrays 

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

**Follow up:** The overall run time complexity should be `O(log (m+n))`.

**Example 1:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

**Example 3:**

```
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
```

**Example 4:**

```
Input: nums1 = [], nums2 = [1]
Output: 1.00000
```

**Example 5:**

```
Input: nums1 = [2], nums2 = []
Output: 2.00000
```

**Constraints:**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

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

