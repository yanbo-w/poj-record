# poj1459

## Description

A power network consists of nodes (power stations, consumers and dispatchers) connected by power transport lines. A node u may be supplied with an amount s(u) >= 0 of power, may produce an amount 0 <= p(u) <= pmax(u) of power, may consume an amount 0 <= c(u) <= min(s(u),cmax(u)) of power, and may deliver an amount d(u)=s(u)+p(u)-c(u) of power. The following restrictions apply: c(u)=0 for any power station, p(u)=0 for any consumer, and p(u)=c(u)=0 for any dispatcher. There is at most one power transport line (u,v) from a node u to a node v in the net; it transports an amount 0 <= l(u,v) <= lmax(u,v) of power delivered by u to v. Let Con=Σuc(u) be the power consumed in the net. The problem is to compute the maximum value of Con.


An example is in figure 1. The label x/y of power station u shows that p(u)=x and pmax(u)=y. The label x/y of consumer u shows that c(u)=x and cmax(u)=y. The label x/y of power transport line (u,v) shows that l(u,v)=x and lmax(u,v)=y. The power consumed is Con=6. Notice that there are other possible states of the network but the value of Con cannot exceed 6.
## Input

There are several data sets in the input. Each data set encodes a power network. It starts with four integers: 0 <= n <= 100 (nodes), 0 <= np <= n (power stations), 0 <= nc <= n (consumers), and 0 <= m <= n^2 (power transport lines). Follow m data triplets (u,v)z, where u and v are node identifiers (starting from 0) and 0 <= z <= 1000 is the value of lmax(u,v). Follow np doublets (u)z, where u is the identifier of a power station and 0 <= z <= 10000 is the value of pmax(u). The data set ends with nc doublets (u)z, where u is the identifier of a consumer and 0 <= z <= 10000 is the value of cmax(u). All input numbers are integers. Except the (u,v)z triplets and the (u)z doublets, which do not contain white spaces, white spaces can occur freely in input. Input data terminate with an end of file and are correct.
Output

For each data set from the input, the program prints on the standard output the maximum amount of power that can be consumed in the corresponding network. Each result has an integral value and is printed from the beginning of a separate line.
## Sample Input

2 1 1 2 (0,1)20 (1,0)10 (0)15 (1)20
7 2 3 13 (0,0)1 (0,1)2 (0,2)5 (1,0)1 (1,2)8 (2,3)1 (2,4)7
         (3,5)2 (3,6)5 (4,2)7 (4,3)5 (4,5)1 (6,0)5
         (0)5 (1)2 (3)2 (4)1 (5)4

## 解题过程与思路

建模两小时，跑通一秒钟。。。。。

研究了好长时间的EK算法，大致思路就是寻找增广路径，但是为了留出反悔的余地，在更新flow和残差网络的时候不仅仅更新正向路径，也更新反向路径，用f(u,v)和-f(u,v)表示。然后在残差图gf上不断bfs寻找源点到汇点之间的增广路径进行更新。在多个源点和汇点的情况下对于每一个源点进行增广，直到找不到为止。

整体思路最开始谢过了，所以还是比较清晰的。

其中bfs还是写的不熟练，用黑白灰加队列来解决，以后。

另外，格式化读写，scanf可以用来对特定符号进行寻找，但是要注意空格的存在。


## 最大流算法

### EK算法

 首先，假如所有边上的流量都没有超过容量(不大于容量)，那么就把这一组流量，或者说，这个流，称为一个可行流。一个最简单的例子就是，零流，即所有的流量都是0的流。
我们就从这个零流开始考虑，假如有这么一条路，这条路从源点开始一直一段一段的连到了汇点，并且，这条路上的每一段都满足流量<容量，注意，是严格的<,而不是<=。那么，我们一定能找到这条路上的每一段的(容量-流量)的值当中的最小值delta。我们把这条路上每一段的流量都加上这个delta，一定可以保证这个流依然是可行流，这是显然的。
    这样我们就得到了一个更大的流，他的流量是之前的流量+delta，而这条路就叫做增广路。
    我们不断地从起点开始寻找增广路，每次都对其进行增广，直到源点和汇点不连通，也就是找不到增广路为止。当找不到增广路的时候，当前的流量就是最大流，这个结论非常重要。
寻找增广路的时候我们可以简单的从源点开始做bfs，并不断修改这条路上的delta量，直到找到源点或者找不到增广路。
这里要先补充一点，在程序实现的时候，我们通常只是用一个c数组来记录容量，而不记录流量，当流量+1的时候，我们可以通过容量-1来实现，以方便程序的实现。


### Dinic算法

Dinic算法的思想也是分阶段地在层次网络中增广。它与最短增广路算法不同之处是：最短增广路每个阶段执行完一次BFS增广后，要重新启动BFS从源点Vs开始寻找另一条增广路;而在Dinic算法中，只需一次DFS过程就可以实现多次增广，这是Dinic算法的巧妙之处。Dinic算法具体步骤如下:

（1）初始化容量网络和网络流。

（2）构造残留网络和层次网络，若汇点不再层次网络中，则算法结束。

（3）在层次网络中用一次DFS过程进行增广，DFS执行完毕，该阶段的增广也执行完毕。

（4）转步骤（2）。

在Dinic的算法步骤中，只有第（3）步与最短增广路相同。在下面实例中，将会发现DFS过程将会使算法的效率有非常大的提高。

### ISAP算法

①过程：

逆向一次BFS分层，即dist为到汇点的最短距离
DFS增广，在增广过程中，如果遇到无法增广的情况下，进行dist数组的更新（即在该点X所连的边指向点中找dist最小的点Y，dist[X]=dist[Y]+1）
直到dist[源点]大于点数的时候，结束算法，返回最大流
结构体Edge中多加一个from变量，指该边从from点指向to点



优化除了弧优化之外多了一个gap优化，指当dist[当前节点]的值在增广中没有其他节点的dist拥有这个值了，就直接返回最大流


下次再研究https://zhuanlan.zhihu.com/p/46039732