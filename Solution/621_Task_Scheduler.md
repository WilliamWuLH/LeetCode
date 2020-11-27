## Task Scheduler

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two **same tasks** (the same letter in the array), that is that there must be at least `n` units of time between any two same tasks.

Return *the least number of units of times that the CPU will take to finish all the given tasks*.

**Example 1:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
```

**Example 2:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
```

**Example 3:**

```
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
```

**Constraints:**

- `1 <= task.length <= 10^4`
- `tasks[i]` is upper-case English letter.
- The integer `n` is in the range `[0, 100]`.

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

