## Accounts Merge

Given a list `accounts`, each element `accounts[i]` is a list of strings, where the first element `accounts[i][0]` is a *name*, and the rest of the elements are *emails* representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails **in sorted order**. The accounts themselves can be returned in any order.

**Example 1:**

```
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
```

**Note:**

The length of `accounts` will be in the range `[1, 1000]`.

The length of `accounts[i]` will be in the range `[1, 10]`.

The length of `accounts[i][j]` will be in the range `[1, 30]`.

#### 并查集 + 哈希表：

​		本题看起来很复杂，写起来也很复杂，但是其实思路的理解和完成并不难。

​		首先，为了缩减空间，我们可以把每个不同的电子邮箱用不同的索引进行表示，这里就有一个哈希表 email2num 用于表示从电子邮箱到整数索引的对应关系。其次，每个电子邮箱和对应的账户名称我们也需要用一个哈希表进行保存，由于此时电子邮箱可以用它的整数索引表示，所以我们使用哈希表 num2name 表示电子邮箱索引到账户名称的对应关系。

​		接下来，通过题目可知，如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

​		所以这里就可以运用并查集的知识了，通过不同账号之间的相同电子邮箱可以把这些账号连接成一个连通分量，把所有电子邮箱放入并查集中进行合并，可以把账号进行合并。

​		最后我们需要把并查集中的电子邮箱和对应的账户名称取出来，通过遍历查找和哈希表映射，把账户的名称和电子邮箱组织成规定的格式（名称位置，电子邮箱的排序），最后得到答案。

​		在进行代码实现时，并查集的实现，哈希表的构建，怎么把电子邮箱进行哈希映射并送给并查集合并，怎么从并查集中进行遍历查找并且组织答案，这些都有编程实现的小技巧，具体看详细代码实现：

```c++
class DSU{
    private:
        unordered_map<int, int> f;
    public:
        int find(int x){
            if(!f.count(x))
                f[x] = x;
            if(x != f[x])
                f[x] = find(f[x]);
            return f[x];
        }
        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            f[x] = y;
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num = 0;
        vector<string> email;
        unordered_map<string, int> email2num;
        unordered_map<int, string> num2name;
        DSU dsu;
        for(auto &i : accounts){
            int n = i.size();
            int the_set;
            for(int k = 1; k < n; k++){
                if(!email2num.count(i[k])){
                    email.emplace_back(i[k]);
                    email2num[i[k]] = num;
                    num2name[num++] = i[0];
                }
                if(k == 1)
                    the_set = dsu.find(email2num[i[k]]);
                else
                    dsu.unionset(email2num[i[k]], the_set);
            }
        }
        vector<vector<string>> ans;
        unordered_map<int, int> name2index;
        int index = 0;
        for(auto &e : email){
            int the_num = email2num[e];
            int the_name = dsu.find(the_num);
            if(!name2index.count(the_name)){
                name2index[the_name] = index++;
                vector<string> temp;
                temp.emplace_back(num2name[the_name]);
                temp.emplace_back(e);
                ans.emplace_back(temp);
            }
            else
                ans[name2index[the_name]].emplace_back(e);
        }
        for(auto &i : ans)
            sort(i.begin()+1, i.end());
        return ans;
    }
};
```

