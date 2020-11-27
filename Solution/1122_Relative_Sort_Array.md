## Relative Sort Array

Given two arrays `arr1` and `arr2`, the elements of `arr2` are distinct, and all elements in `arr2` are also in `arr1`.

Sort the elements of `arr1` such that the relative ordering of items in `arr1` are the same as in `arr2`. Elements that don't appear in `arr2` should be placed at the end of `arr1` in **ascending** order.

**Example 1:**

```
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

**Constraints:**

- `1 <= arr1.length, arr2.length <= 1000`
- `0 <= arr1[i], arr2[i] <= 1000`
- All the elements of `arr2` are **distinct**.
- Each `arr2[i]` is in `arr1`.

#### 数组的相对排序：

​		首先按照 arr2 的顺序，在 arr1 中找出所有和 arr2 元素相同的数，并且加入到答案数组中，再把 arr1 中的该数删除，最后在 arr1 中剩下的就只有在 arr2 中没有的元素，而答案数组 ans 中的元素则是 arr1 中相对于 arr2 的顺序排序好的。接下来把 arr1 中剩下的元素按照升序排列，再把它们插入到答案数组 ans 的末尾，完成！

```c++
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for(auto k : arr2){
            for(int i=0; i<arr1.size(); i++){
                if(arr1[i] == k){
                    ans.push_back(k);
                    arr1.erase(arr1.begin()+i);
                    i--;
                }
            }
        }
        sort(arr1.begin(), arr1.end());
        for(auto k : arr1)
            ans.push_back(k);
        return ans;
    }
};
```

