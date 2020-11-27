## Minimum Increment to Make Array Unique

Given an array of integers A, a *move* consists of choosing any `A[i]`, and incrementing it by `1`.

Return the least number of moves to make every value in `A` unique.

**Example 1:**

```
Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
```

**Example 2:**

```
Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
```

**Note:**

1. `0 <= A.length <= 40000`
2. `0 <= A[i] < 40000`

#### 计数 + 排序：

```c++
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int,int> count;
        int ans = 0;
        int len = A.size();
        for(int i=0; i<len; i++){
            count[A[i]]++;
        }
        map<int,int>::iterator mit;
        for(mit=count.begin(); ; mit++){
            if(mit == count.end()){
                int temp = mit->second - 1;
                ans += (1 + temp) * temp * 0.5;
                break;
            }
            int num = mit->first;
            if(count[num] > 1){
                int temp = mit->second - 1;
                count[num+1] += temp;
                ans += temp;
            }
        }
        return ans;
    }
};
```

