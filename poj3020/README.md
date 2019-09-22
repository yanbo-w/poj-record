# poj3020

## Description

The Global Aerial Research Centre has been allotted the task of building the fifth generation of mobile phone nets in Sweden. The most striking reason why they got the job, is their discovery of a new, highly noise resistant, antenna. It is called 4DAir, and comes in four types. Each type can only transmit and receive signals in a direction aligned with a (slightly skewed) latitudinal and longitudinal grid, because of the interacting electromagnetic field of the earth. The four types correspond to antennas operating in the directions north, west, south, and east, respectively. Below is an example picture of places of interest, depicted by twelve small rings, and nine 4DAir antennas depicted by ellipses covering them.

Obviously, it is desirable to use as few antennas as possible, but still provide coverage for each place of interest. We model the problem as follows: Let A be a rectangular matrix describing the surface of Sweden, where an entry of A either is a point of interest, which must be covered by at least one antenna, or empty space. Antennas can only be positioned at an entry in A. When an antenna is placed at row r and column c, this entry is considered covered, but also one of the neighbouring entries (c+1,r),(c,r+1),(c-1,r), or (c,r-1), is covered depending on the type chosen for this particular antenna. What is the least number of antennas for which there exists a placement in A such that all points of interest are covered?

## Input

On the first row of input is a single positive integer n, specifying the number of scenarios that follow. Each scenario begins with a row containing two positive integers h and w, with 1 <= h <= 40 and 0 < w <= 10. Thereafter is a matrix presented, describing the points of interest in Sweden in the form of h lines, each containing w characters from the set ['*','o']. A '*'-character symbolises a point of interest, whereas a 'o'-character represents open space.

## Output

For each scenario, output the minimum number of antennas necessary to cover all '*'-entries in the scenario's matrix, on a row of its own.

## 解题过程

最开始想到用二分图的算法来做这道题。

考虑了一下，觉得如果要构造二分图的话，可以将棋盘分为两种格子，像国际象棋一样，但是自己只是简单的用顺序来确定格子的颜色了，其实画出来国际象棋的棋盘你会发现，
黑白的区分是在于(x+y)%2是否为0，而不是(x*w+y)%2，这样犯了一个比较大的错误。

后来发现网上别人是用构造两倍边数的图，最后结果也除以二得到的，是很聪明。两倍的边数，这样求g的时候方便了很多。而且也是满足二分的图的。

总结一下，黑白棋盘的黑白是由x+y决定的，而序号则是由(x*w+y)/2决定的。

## 二分图的性质

总结：

【无向图的最大独立数】: 从V个顶点中选出k个顶，使得这k个顶互不相邻。 那么最大的k就是这个图的最大独立数。

【无向图的最大团】:  从V个顶点选出k个顶，使得这k个顶构成一个完全图，即该子图任意两个顶都有直接的边。

【最小路径覆盖(原图不一定是二分图，但必须是有向图，拆点构造二分图)】：在图中找一些路径，使之覆盖了图中的所有顶点，且任何一个顶点有且只有一条路径与之关联。最小路径覆盖 = |V| - 最大匹配数

【最小边覆盖(原图是二分图)】：在图中找一些边，使之覆盖了图中所有顶点，且任何一个顶点有且只有一条边与之关联。最小边覆盖 = 最大独立集 = |V| - 最大匹配数

【最小顶点覆盖】：用最少的点（左右两边集合的点）让每条边都至少和其中一个点关联。

d.最大点独立集：无向图G中，点数最多的点独立集
最小边覆盖 = 最大独立集 = n - 最大匹配
————————————————
版权声明：本文为CSDN博主「leolin_」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/leolin_/article/details/7199688

二分图的一个等价定义是：不含有「含奇数条边的环」的图