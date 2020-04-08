## Top K Frequent Elements

#### map 哈希统计数字出现次数，priority_queue 优先队列进行优先级排序：

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        map<int, int>::iterator mit;
        for(mit=count.begin(); mit!=count.end(); mit++){
            pq.push(make_pair(mit->second,mit->first));
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```

