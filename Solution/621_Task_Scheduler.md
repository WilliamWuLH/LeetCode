## Task Scheduler

#### 排序 + 按任务个数安排：

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int count[26];
        memset(count, 0, 26*sizeof(int));
        for(auto i : tasks)
            count[i-'A']++;
        sort(count,count+26);
        while(count[25]){
            int time = 0;
            while(time <= n){
                if(count[25] == 0)
                    break;
                if(time < 26 && count[25-time])
                    count[25-time]--;
                time++;
                ans++;
            }
            sort(count,count+26);
        }
        return ans;
    }
};
```

#### 数学思维：

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxnum = 1;
        int count[26];
        memset(count, 0, 26*sizeof(int));
        for(auto i : tasks)
            count[i-'A']++;
        sort(count, count+26);
        for(int i=24; i >= 0; i--){
            if(count[i] != count[25])
                break;
            maxnum++;
        }
        return max(int(tasks.size()), (count[25]-1)*(n+1)+maxnum);
    }
};
```

