## K Closest Points to Origin

#### 计算距离 + 排序：

​		求最接近原点的 K 个点，先对每一个点求点到原点的距离，然后再根据距离进行排序，取出其中距离最小，也就是最接近原点的 K 个点。

```c++
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        typedef pair<vector<int>, long> the_point;
        vector<the_point> v;
        vector<vector<int>> ans;
        for(int i=0; i<points.size(); i++){
            long d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            v.push_back(the_point(points[i], d));
        }
        sort(v.begin(), v.end(), [&](const the_point &a, const the_point b){
            if(a.second < b.second)
                return true;
            return false;
        });
        for(int i=0; i<K; i++)
            ans.push_back(v[i].first);
        return ans;
    }
};
```

