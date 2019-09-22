# poj3041

## Description

Bessie wants to navigate her spaceship through a dangerous asteroid field in the shape of an N x N grid (1 <= N <= 500). The grid contains K asteroids (1 <= K <= 10,000), which are conveniently located at the lattice points of the grid.

Fortunately, Bessie has a powerful weapon that can vaporize all the asteroids in any given row or column of the grid with a single shot.This weapon is quite expensive, so she wishes to use it sparingly.Given the location of all the asteroids in the field, find the minimum number of shots Bessie needs to fire to eliminate all of the asteroids.
## Input

* Line 1: Two integers N and K, separated by a single space.
* Lines 2..K+1: Each line contains two space-separated integers R and C (1 <= R, C <= N) denoting the row and column coordinates of an asteroid, respectively.
## Output

* Line 1: The integer representing the minimum number of times Bessie must shoot.

## 二分图最大匹配问题

二分图最大匹配问题是寻找两两配对的最优解，最多匹配。其实和流是差不多的，可以用最大流的算法，添加两个节点。

此外就是匈牙利算法，主要的核心思想就是“腾”，左侧为准，依次向右侧找，如果已经被访问了就腾，找到增广路径替换。

DFS写法就比较简单了，循环判断。

此外，最好不要用char，容易出问题，不明白，memset最好只用作初始化0。

##  二分图性质

二分图有两个定理：最小覆盖数=最大匹配数、最大独立集=总数-最小覆盖集 。

几个基本定义：

最小覆盖：即在所有顶点中选择最少的顶点来覆盖所有的边。

最大匹配：二分图左右两个点集中，选择有边相连的两个匹配成一对（每个点只能匹配一次），所能达到的最大匹配数。

最大独立集：集合中的任何两个点都不直接相连。

[最小覆盖数=最大匹配数证明：](https://blog.csdn.net/Techmonster/article/details/50011363)