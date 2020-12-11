## Dota2 Senate

In the world of Dota2, there are two parties: the `Radiant` and the `Dire`.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise `one` of the two rights:

1. `Ban one senator's right`:
   A senator can make another senator lose **all his rights** in this and all the following rounds.
2. `Announce the victory`:
   If this senator found the senators who still have rights to vote are all from **the same party**, he can announce the victory and make the decision about the change in the game.

Given a string representing each senator's party belonging. The character 'R' and 'D' represent the `Radiant` party and the `Dire` party respectively. Then if there are `n` senators, the size of the given string will be `n`.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce the victory and make the change in the Dota2 game. The output should be `Radiant` or `Dire`.

**Example 1:**

```
Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights any more since his right has been banned. 
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
```

**Example 2:**

```
Input: "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in the round 1. 
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
```

**Note:**

1. The length of the given string will in the range [1, 10,000].

#### 循环队列 + 贪心：

​		 Radiant 和 Dire 两个阵营，只要其中一个阵营的人全部失去了权利，则另一方宣布获胜。

​		首先遍历一遍字符串，使用两个队列：Radiant 和 Dire 分别按照先后顺序存储各自阵营的人员的序号。

​		所以此时有一方获胜的情况是：Radiant 和 Dire 中某一个队列为空，则另一个阵营胜利。

​		在每一轮中的行使权利过程：

- 如果此时 Radiant 队列队首的数比 Dire 队列队首的数小，说明此时 Radiant 队列队首的人员在 Dire 队列队首的人员前面，可以先禁止 Dire 队列队首人员的权利，并且本轮中后续的人不能禁止此时这个 Radiant 队列队首的人员。所以弹出 Radiant 和 Dire 的队首元素，并且在 Radiant 队尾添加一个元素，元素值为：Radiant 弹出的元素值 + n，表示下一轮的数值。

- 否则，如果此时 Radiant 队列队首的数比 Dire 队列队首的数大，说明此时 Radiant 队列队首的人员在 Dire 队列队首的人员后面，Dire 队列队首人员可以先禁止 Radiant 队列队首人员的权利，并且本轮中后续的人不能禁止此时这个 Dire 队列队首的人员。所以弹出 Radiant 和 Dire 的队首元素，并且在 Dire 队尾添加一个元素，元素值为：Dire 弹出的元素值 + n，表示下一轮的数值。

  ​	最后有一个队列为空，以此判断哪个阵营获胜。

```c++
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> Radiant, Dire;
        for(int i=0; i<n; i++){
            if(senate[i] == 'R')
                Radiant.push(i);
            else
                Dire.push(i);
        }
        while(!Radiant.empty() && !Dire.empty()){
            if(Radiant.front() < Dire.front())
                Radiant.push(Radiant.front()+n);
            else
                Dire.push(Dire.front()+n);
            Radiant.pop();
            Dire.pop();
        }
        return Radiant.empty() ? "Dire" : "Radiant";
    }
};
```

