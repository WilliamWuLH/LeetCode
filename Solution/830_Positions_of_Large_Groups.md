## Positions of Large Groups

In a string `s` of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like `s = "abbxxxxzyy"` has the groups `"a"`, `"bb"`, `"xxxx"`, `"z"`, and `"yy"`.

A group is identified by an interval `[start, end]`, where `start` and `end` denote the start and end indices (inclusive) of the group. In the above example, `"xxxx"` has the interval `[3,6]`.

A group is considered **large** if it has 3 or more characters.

Return *the intervals of every **large** group sorted in **increasing order by start index***.

**Example 1:**

```
Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
```

**Example 2:**

```
Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.
```

**Example 3:**

```
Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
```

**Example 4:**

```
Input: s = "aba"
Output: []
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` contains lower-case English letters only.

#### 遍历 + 判断：

​		很简单，从头到尾遍历字符串，判断出满足较大分组条件的分组，记录这些分组的起始地址和终止地址，并且及时添加到最终的答案中。

​		小技巧：由于字符串由小写字母构成，所以可以在字符串后面添加一个非小写字母的字符，这样原字符串的最后一个字符也可以和前面的字符一样正常讨论，使得代码更加简洁。

​		具体实现看代码，十分好理解。

```c++
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        s += '$';
        int n = s.length();
        vector<int> cur(2, 0);
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1])
                cur[1] = i;
            else{
                if(cur[1] - cur[0] >= 2)
                    ans.push_back(cur);
                cur[0] = i;
            }
        }
        return ans;
    }
};
```

