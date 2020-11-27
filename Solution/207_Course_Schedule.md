## Course Schedule

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses-1`.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: `[0,1]`

Given the total number of courses and a list of prerequisite **pairs**, is it possible for you to finish all courses?

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
```

**Constraints:**

- The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about [how a graph is represented](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).
- You may assume that there are no duplicate edges in the input prerequisites.
- `1 <= numCourses <= 10^5`

#### 宽度优先搜索 BFS 实现拓扑排序：

​		首先把边缘列表表示的图转为邻接表表示的图。

​		然后找出所有入度为 0 的结点，插入队列中，入度为 0 即表示此时没有前导课程的结点。

​		判断队列不为空时，取出队首元素，找到它可以到达的结点，将这些结点的入度都减去 1 并去掉此时取出的队首元素，表示这个课程已经学过了讨论过了，可以进入下一门课程，此时学过的课程数目要加一。

​		在讨论队列中每一个元素的同时需要判断此时哪些结点的入度为 0，将入度为 0 的结点添加到队列中。

​		最后判断学过的课程数目是否等于总课程数目，以此来得到答案。

​		以上的这个过程其实就是判断图是否是有向无环图 DAG （Directed acyclic graph）的过程。

​		如果图中存在环，则成环的结点的入度将永远不为 0，那么这些结点将永远进不了队列，这些课程将永远无法学习，最终的学过的课程数目将少于总的课程数目。

​		如果图是有向无环图 DAG，则图中不存在环，每个结点经过计算最后的入度都会变为 0，最终学过的课程数目将等于总的课程数目。

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        int before[numCourses];
        memset(before, 0, numCourses*sizeof(int));
        vector<vector<int>> graph(numCourses);
        vector<vector<int>>::iterator it;
        for(it = prerequisites.begin(); it != prerequisites.end(); it++){
            graph[ (*it)[0] ].push_back( (*it)[1] );
            before[ (*it)[1] ]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(before[i] == 0)
                q.push(i);
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            vector<int>::iterator i;
            for(i = graph[course].begin(); i != graph[course].end(); i++){
                before[*i]--;
                if(before[*i] == 0)
                    q.push(*i);
            }
        }
        return count == numCourses;
    }
};
```

