# Poj1860
Tags：图遍历，bellman ford算法
## Description
Several currency exchange points are working in our city. Let us suppose that each point specializes in two particular currencies and performs exchange operations only with these currencies. There can be several points specializing in the same pair of currencies. Each point has its own exchange rates, exchange rate of A to B is the quantity of B you get for 1A. Also each exchange point has some commission, the sum you have to pay for your exchange operation. Commission is always collected in source currency. 
For example, if you want to exchange 100 US Dollars into Russian Rubles at the exchange point, where the exchange rate is 29.75, and the commission is 0.39 you will get (100 - 0.39) * 29.75 = 2963.3975RUR. 
You surely know that there are N different currencies you can deal with in our city. Let us assign unique integer number from 1 to N to each currency. Then each exchange point can be described with 6 numbers: integer A and B - numbers of currencies it exchanges, and real RAB, CAB, RBA and CBA - exchange rates and commissions when exchanging A to B and B to A respectively. 
Nick has some money in currency S and wonders if he can somehow, after some exchange operations, increase his capital. Of course, he wants to have his money in currency S in the end. Help him to answer this difficult question. Nick must always have non-negative sum of money while making his operations. 

## Input
The first line of the input contains four numbers: N - the number of currencies, M - the number of exchange points, S - the number of currency Nick has and V - the quantity of currency units he has. The following M lines contain 6 numbers each - the description of the corresponding exchange point - in specified above order. Numbers are separated by one or more spaces. 1<=S<=N<=100, 1<=M<=100, V is real number, 0<=V<=103. 
For each point exchange rates and commissions are real, given with at most two digits after the decimal point, 10-2<=rate<=102, 0<=commission<=102. 
Let us call some sequence of the exchange operations simple if no exchange point is used more than once in this sequence. You may assume that ratio of the numeric values of the sums at the end and at the beginning of any simple sequence of the exchange operations will be less than 104. 

## Output

If Nick can increase his wealth, output YES, in other case output NO to the output file.

## 解题过程

最开始没有思路，但是看到了评论区里有说bellman ford算法的比较多，于是尝试了使用该算法，完成了AC。

其实就是一个寻找负回路的过程，最开始的思路没有问题。

审题过程中知道要用图数据结构存储，于是使用了邻接表来做，事实证明，本题数据量不大，所以存储空间省不了多少。

此外，自己多考虑了同一对节点之间存在多边的情况，但是大部分代码都没体现，在实现过程中我也没有采用，但其实看来是侥幸过（ Let us suppose that each point specializes in two particular currencies and performs exchange operations only with these currencies. There can be several points specializing in the same pair of currencies），大家都没考虑这种情况？

不对不对，自己还是考虑了的，邻接表里面有重复的边，权重不一样而已，其他人很多直接节点和边分开存的，也挺好，值得借鉴，如果任务是按边遍历的话。

此外，bellman ford算法还需要再看看，目前只是会用了。

关于c++的语言结构，这次用了vector，感觉很好用，以后可以多用用，这次也慢慢熟练起来了。但其实效率最高最快的还是简单的数组。

此外，disscuss区里面有提到spfa闭环，此外，其他的遍历算法也要多看看。

对了，这次有一个教训，就是，现实世界的1对应计算机中的0的问题，有一个比较好的方法就是，只在输入输出的时候做处理，中间的时候全部都按照计算机中的来，可以最大限度减少错误。

有一个事情也值得去总结一下，就是while判断循环条件的问题，到底是先取值还是先判断，即移动与判断越界的先后问题。