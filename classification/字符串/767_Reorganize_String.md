## Reorganize String

Given a string `S`, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result. If not possible, return the empty string.

**Example 1:**

```
Input: S = "aab"
Output: "aba"
```

**Example 2:**

```
Input: S = "aaab"
Output: ""
```

**Note:**

- `S` will consist of lowercase letters and have length in range `[1, 500]`.

#### 计数 + 排序 + 重组：

​		首先，统计字符串中每个字符的个数，在进行字符统计的过程中就可以判断这个字符串能不能进行重构，通过判断某一个字符的出现次数是否超过 (n+1)/2。

​		得到字符串中每个字符对应的个数之后，我们要依据字符个数对每个字符进行排序，之后再按照从大到小的顺序进行重组。

​		如何进行重组？按照字符个数从大到小的顺序依次将字符放入特定的位置，先将字符把字符串中的奇数位置填满，然后再按顺序把偶数位置填满，这样相同的字符就一定不会相邻。

​		为什么先填奇数位置，再填偶数位置？因为在一个字符串中，奇数位置的个数总是大于等于偶数位置的个数。

​		为什么要依据字符个数对每个字符进行排序？举个例子：abvvv。

```c++
class Solution {
public:
    string reorganizeString(string S) {
        int count[26];
        int n = S.length();
        memset(count, 0, sizeof(int)*26);
        for(auto i : S){
            count[i-'a'] += 100;
            if(count[i-'a']/100 > (n+1)/2)
                return "";
        }
        for(int i=0; i<26; i++)
            count[i] += i;
        sort(count, count+26);
        int pos = 0;
        string ans = S;
        for(int i=25; i>=0; i--){
            if(count[i] < 100)
                break;
            char cur = 'a'+count[i]%100;
            int num = count[i]/100;
            while(num){
                ans[pos] = cur;
                pos += 2;
                if(pos >= n)
                    pos = 1;
                num--;
            }
        }
        return ans;
    }
};
```

