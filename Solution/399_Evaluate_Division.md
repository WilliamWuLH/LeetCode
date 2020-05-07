## Evaluate Division

#### 带权值的并查集：

​		并查集的详细说明请自行百度。

​		解答详见注释。

```c++
class Solution {
public:
    map<string, string> theset;
    map<string, double> value;
    //若并查集中还没有 x 结点，添加 x 结点
    void add(string x){
        if(theset.count(x) == 0){
            theset[x] = x;
            value[x] = 1.0;
        }
    }
    //找到 x 结点所属的集（根结点）
    string find_root(string x){
        while(theset[x] != x){
            x = theset[x];
        }
        return x;
    }
    //计算得到 x 结点到根结点（集）的路径乘积
    double get_value(string x){
        double ans = 1;
        while(theset[x] != x){
            ans *= value[x];
            x = theset[x];
        }
        return ans;
    }
    //合并两个结点的集，如果相同的集就不用合并，若不同集则合并为同一个集
    void merge(string a, string b, double val){
        add(a);
        add(b);
        string aroot = find_root(a);
        string broot = find_root(b);
        if(aroot != broot){
            theset[broot] = aroot;
            //计算两个集之间值的比例关系
            value[broot] = val * (get_value(a) / get_value(b));
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        //添加、合并结点，得到并查集
        for(int i=0; i<equations.size(); i++)
            merge(equations[i][0], equations[i][1], values[i]);
        //计算答案
        for(int i=0; i<queries.size(); i++){
            //并查集中无该结点
            if(theset.count(queries[i][0]) == 0 || theset.count(queries[i][1]) == 0){
                ans.push_back(-1);
                continue;
            }
            //两个结点相同
            else if(queries[i][0] == queries[i][1]){
                ans.push_back(1);
                continue;
            }
            string aroot = find_root(queries[i][0]);
            string broot = find_root(queries[i][1]);
            //两个结点属于不同集（无路径联通）
            if(aroot != broot){
                ans.push_back(-1);
                continue;
            }
            //计算答案
            ans.push_back(get_value(queries[i][1]) / get_value(queries[i][0]));
        }
        return ans;
    }
};
```

