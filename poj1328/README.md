<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

# Poj1328
## Description
Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d. 

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates. 

![](http://poj.org/images/1328_1.jpg)


## Test Case
```
2 5
-3 4
-6 3

4 5
-5 3
-3 5
2 3
3 3

20 8
-20 7
-18 6
-5 8
-21 8
-15 7
-17 5
-1 5
-2 3
-9 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 7
9 6
10 5
0 0

2 3
0 2
2 3

2 3
0 2
1 3

3 3
1 2
-3 2
2 4

8 5
2 4
-4 4
-3 3
-3 1
-3 0
-1 0
0 5
6 0

3 0
1 2
-3 1
2 1

3 2
1 2
-3 1
2 1

1 2
0 2

2 3
0 2
2 3

4 -5
4 3
4 3
2 3
6 -9

3 -3
1 2
-3 2
2 1

6 2
1 2
1 2
1 2
-3 1
2 1
0 0

1 2
0 2

2 3
0 2
1 3

3 10
1 10
2 3
4 5

3 5
1 10
2 3
4 5

4 7
1 10
2 3
4 5
0 0

3 9
1 10
2 3
4 5

2 2
-1 1
2 1

 8 1
 4 0
 3 0
 5 0
 7 0
-5 0
-4 0
-3 0
 1 0

2 5
0 3
8 3

0 0
```
### Result

```
Case 1: 1
Case 2: 2
Case 3: 4
Case 4: 1
Case 5: 1
Case 6: -1
Case 7: 3
Case 8: -1
Case 9: 2
Case 10: 1
Case 11: 1
Case 12: -1
Case 13: -1
Case 14: 2
Case 15: 1
Case 16: 1
Case 17: 1
Case 18: -1
Case 19: -1
Case 20: -1
Case 21: 1
Case 22: 4
Case 23: 1
```

### 解题思路

最开始想到边界，在边界试探一下，最坏的情况是

$$\exists i,st.d<y_i$$

这种情况是不行的，然后边界上是

$$\exists i,st.d=y_i$$

这种情况就被限定死了，只能有一个圆在\\(x_i\\)处。给出启发来，也就是说任何一个点，当点在圆上的时候是局部的最优，因此对于任意一个点，可以做出两个圆来，分别以该点为圆心与x轴的两个交点为圆心。（后面发现其实可以转换成区间的问题，考虑起来更清楚）再考虑每个点作出了两个圆，怎么将这些圆数目减少到最小。

最开始考虑任意取圆，如果点包含在内就取消，后来发现这种算法不能提供最优解，因此要从左向右一步步缩减，能够得到最优解。

也就是采用贪心算法，寻找局部最优，极端取值。

> 贪心算法的基本要素
>  
> 1．贪心选择性质 
> 
> 所谓贪心选择性质是指所求问题的整体最优解可以通过一系列局部最优的选择，即贪心选择来达到。这是贪心算法可行的第一个基本要素，也是贪心算法与动态规划算法的主要区别。在动态规划算法中，每步所作的选择往往依赖于相关子问题的解。因而只有在解出相关子问题后，才能作出选择。而在贪心算法中，仅在当前状态下作出最好选择，即局部最优选择。然后再去解作出这个选择后产生的相应的子问题。贪心算法所作的贪心选择可以依赖于以往所作过的选择，但决不依赖于将来所作的选择，也不依赖于子问题的解。正是由于这种差别，动态规划算法通常以自底向上的方式解各子问题，而贪心算法则通常以自顶向下的方式进行,以迭代的方式作出相继的贪心选择，每作一次贪心选择就将所求问题简化为一个规模更小的子问题。 
> 
> 对于一个具体问题，要确定它是否具有贪心选择性质，我们必须证明每一步所作的贪心选择最终导致问题的一个整体最优解。通常可以用我们在证明活动安排问题的贪心选择性质时所采用的方法来证明。首先考察问题的一个整体最优解，并证明可修改这个最优解，使其以贪心选择开始。而且作了贪心选择后，原问题简化为一个规模更小的类似子问题。然后，用数学归纳法证明，通过每一步作贪心选择，最终可得到问题的一个整体最优解。其中，证明贪心选择后的问题简化为规模更小的类似子问题的关键在于利用该问题的最优子结构性质。 
> 
> 2．最优子结构性质 
> 
> 当一个问题的最优解包含着它的子问题的最优解时，称此问题具有最优子结构性质。问题所具有的这个性质是该问题可用动态规划算法或贪心算法求解的一个关键特征。在活动安排问题中，其最优子结构性质表现为：若a是对于整体活动安排问题包含活动1的一个最优解,则相容活动集合a’=a—{1}是对于e’={i∈e:si≥f1}的活动安排问题的一个最优解。


要想证明的话就是从两方面出发：

1. 贪心选择性质：一个全局最优解可以通过局部最优得到。即存在一个最优解是以贪心选择开始的。
2. 最优子结构：如果问题的最优解所包含的子问题的解也是最优的，我们就称该问题具有最优子结构性质（即满足最优化原理)。可以这么理解，每一步贪心对于后一步的问题解没有影响的话，就说明有最优子结构，体现的是独立性。

现在证明的话，首先通过上述算法得到的雷达站集合是满足条件的，并且如果以第一个区间的右端点为第一座雷达站的坐标的话，所能够辐射到的岛屿数目一定是最多的（和其他位置相比），因此可以证明局部最优。贪心性质还是比较好证明的，但是看了一圈网上证明最优子结构的，感觉都差那么一点。

Wikipedia上面对于最优子结构的举例如下。
>Consider finding a shortest path for travelling between two cities by car, as illustrated in Figure 1. Such an example is likely to exhibit optimal substructure. That is, if the shortest route from Seattle to Los Angeles passes through Portland and then Sacramento, then the shortest route from Portland to Los Angeles must pass through Sacramento too. That is, the problem of how to get from Portland to Los Angeles is nested inside the problem of how to get from Seattle to Los Angeles. (The wavy lines in the graph represent solutions to the subproblems.)
>
>As an example of a problem that is unlikely to exhibit optimal substructure, consider the problem of finding the cheapest airline ticket from Buenos Aires to Kyiv. Even if that ticket involves stops in Miami and then London, we can't conclude that the cheapest ticket from Miami to Kyiv stops in London, because the price at which an airline sells a multi-flight trip is usually not the sum of the prices at which it would sell the individual flights in the trip.

关于最优子结构的定义为
>In computer science, a problem is said to have optimal substructure if an optimal solution can be constructed from optimal solutions of its subproblems. 
>
>A slightly more formal definition of optimal substructure can be given. Let a "problem" be a collection of "alternatives", and let each alternative have an associated cost, c(a). The task is to find a set of alternatives that minimizes c(a). Suppose that the alternatives can be partitioned into subsets, i.e. each alternative belongs to only one subset. Suppose each subset has its own cost function. The minima of each of these cost functions can be found, as can the minima of the global cost function, restricted to the same subsets. If these minima match for each subset, then it's almost obvious that a global minimum can be picked not out of the full set of alternatives, but out of only the set that consists of the minima of the smaller, local cost functions we have defined. If minimizing the local functions is a problem of "lower order", and (specifically) if, after a finite number of these reductions, the problem becomes trivial, then the problem has an optimal substructure.


目前的理解，最优子结构在这里的证明是：如果我们采用最终得到island(n)的解为radar(n)，一步贪心选取的最左面radar(1)包含进去的岛屿为island(1)，需要证明radar(n-1)是island(n-1)的最优解。这是显然的，因为我们在算法的过程中，每一次找完radar(1)对应的island(1)之后，剩下的island(n-1)全部都是没有被包含进去的，独立开了，所以后面得到的子问题的解是包含在前一步的问题解中的。

### 排雷
1. 坐标不一定是整数点；
2. 为什么用g++提交就TLE，c++就能通过；
3. 评论区有人说cin读double巨慢，所以会被卡；

### 其他
最近刚好有一个新闻，说清华博士用贪心算法找车，哈哈哈，笑死了，很巧。

[清华毕业计算机教授遭持枪劫车！靠 “贪心算法” 追回秒杀美国警察](https://zhuanlan.zhihu.com/p/54114112)