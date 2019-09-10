# poj2485

## Description

The island nation of Flatopia is perfectly flat. Unfortunately, Flatopia has no public highways. So the traffic is difficult in Flatopia. The Flatopian government is aware of this problem. They're planning to build some highways so that it will be possible to drive between any pair of towns without leaving the highway system.

Flatopian towns are numbered from 1 to N. Each highway connects exactly two towns. All highways follow straight lines. All highways can be used in both directions. Highways can freely cross each other, but a driver can only switch between highways at a town that is located at the end of both highways.

The Flatopian government wants to minimize the length of the longest highway to be built. However, they want to guarantee that every town is highway-reachable from every other town.
## Input

The first line of input is an integer T, which tells how many test cases followed.
The first line of each case is an integer N (3 <= N <= 500), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 65536]) between village i and village j. There is an empty line after each test case.
## Output

For each test case, you should output a line contains an integer, which is the length of the longest road to be built such that all the villages are connected, and this value is minimum.

## 解题思路

其实这道题是和prim以及krustal等价的一道题目，证明大概就是最小生成树的边权序列是唯一的，如果存在一个生成树最小的边权l小于原来的L，那么T去掉L之后的两个不连通集在新的t中必定有一个更小的边连接起来，因此与安全边矛盾。

下面是生成树的一些性质。（上面运用了切割性质）
（1）切割性质：（各边边权均不相同）一条边是连接某两个集合的最小边，那么这条边就在最小生成树中
（2）回路性质：（各边边权均不相同）图若有回路，那么回路中的最长边一定不在最小生成树中
增量最小生成树：(动态加边，对于每条边加入后输出当前最小生成树)，根据 “回路性质”复杂度O(n*m)
最小瓶颈生成树：(最大边权值尽量小)，最小生成树就是这么一棵树
最小瓶颈路：（u到v的路径满足最大边权值尽量小），先求最小生成树，然后u到v的路径在树上是唯一的，取路径中最长的一条。
求任意两点的最小瓶颈路：O(n)枚举一个点，然后O(n)树形dp，总体复杂度O(n^2)。
次小生成树：1.prim()扩展，跟次短路一样的算法
2.先求最小生成树，每当边<u,v>加入后就会有环，删除环上除了边<u,v>以外的最长边(也就是删去u到v 之间的最小瓶颈路),所以先求出“任意两点的最小瓶颈路”(上面有)。

其实自己在构造算法的时候，从边小到大遍历，然后生长森林，这个过程得到了和krustal一样的算法。

使用并查集的方法完成不相交森林的构建，注意union之前要先判断是否满足findset的不同，导致我这道题re了很多次。

测试数据见data.in