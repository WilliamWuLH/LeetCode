## K Closest Points to Origin

We have a list of `points` on the plane. Find the `K` closest points to the origin `(0, 0)`.

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

**Example 1:**

```
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
```

**Example 2:**

```
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
```

**Note:**

1. `1 <= K <= points.length <= 10000`
2. `-10000 < points[i][0] < 10000`
3. `-10000 < points[i][1] < 10000`

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

