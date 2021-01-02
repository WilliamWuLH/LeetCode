## Check Array Formation Through Concatenation

You are given an array of **distinct** integers `arr` and an array of integer arrays `pieces`, where the integers in `pieces` are **distinct**. Your goal is to form `arr` by concatenating the arrays in `pieces` **in any order**. However, you are **not** allowed to reorder the integers in each array `pieces[i]`.

Return `true` *if it is possible* *to form the array* `arr` *from* `pieces`. Otherwise, return `false`.

**Example 1:**

```
Input: arr = [85], pieces = [[85]]
Output: true
```

**Example 2:**

```
Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
```

**Example 3:**

```
Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
```

**Example 4:**

```
Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
```

**Example 5:**

```
Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
```

**Constraints:**

- `1 <= pieces.length <= arr.length <= 100`
- `sum(pieces[i].length) == arr.length`
- `1 <= pieces[i].length <= arr.length`
- `1 <= arr[i], pieces[i][j] <= 100`
- The integers in `arr` are **distinct**.
- The integers in `pieces` are **distinct** (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

#### 哈希 + 遍历：

​		第一步：哈希。将 pieces 中的数组元素构建成哈希表的形式，其中 key 为每一个数组元素的第一个数的值，value 为这个数组元素对应在 pieces 中的位置。这样方便我们在遍历 arr 查找数组元素时进行快速定位和判断。

​		第二步：遍历。遍历 arr 中的元素：

- 如果 arr 中的元素在 pieces 中没有找到对应的数组元素，则直接返回 false。
- 如果找到在 pieces 中对应的数组元素，继续遍历，判断 arr 和这个数组元素是否完全匹配，如果不匹配，直接返回 false，如果匹配，继续遍历下一个元素。

```c++
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> hash;
        int plen = pieces.size();
        int alen = arr.size();
        for(int i=0; i<plen; i++)
            hash[pieces[i][0]] = i;
        for(int i=0; i<alen; ){
            if(hash.find(arr[i]) == hash.end())
                return false;
            vector<int> &cur = pieces[hash[arr[i]]];
            int curlen = cur.size();
            for(int j=0; j<curlen; j++, i++)
                if(arr[i] != cur[j])
                    return false;
        }
        return true;
    }
};
```

