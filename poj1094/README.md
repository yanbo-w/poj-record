# poj1094

## Description

An ascending sorted sequence of distinct values is one in which some form of a less-than operator is used to order the elements from smallest to largest. For example, the sorted sequence A, B, C, D implies that A < B, B < C and C < D. in this problem, we will give you a set of relations of the form A < B and ask you to determine whether a sorted order has been specified or not.
## Input

Input consists of multiple problem instances. Each instance starts with a line containing two positive integers n and m. the first value indicated the number of objects to sort, where 2 <= n <= 26. The objects to be sorted will be the first n characters of the uppercase alphabet. The second value m indicates the number of relations of the form A < B which will be given in this problem instance. Next will be m lines, each containing one such relation consisting of three characters: an uppercase letter, the character "<" and a second uppercase letter. No letter will be outside the range of the first n letters of the alphabet. Values of n = m = 0 indicate end of input.
## Output

For each problem instance, output consists of one line. This line should be one of the following three:

Sorted sequence determined after xxx relations: yyy...y.
Sorted sequence cannot be determined.
Inconsistency found after xxx relations.

where xxx is the number of relations processed at the time either a sorted sequence is determined or an inconsistency is found, whichever comes first, and yyy...y is the sorted, ascending sequence.


## 解题过程

最开始尝试用father和child来做，但是发现自己考虑简单了。

出现了一个特别傻Ⅹ的错误，就是在声明了全局变量之后又定义了一次局部变量，导致出现错误，详情见tst.cpp，当时看的我都傻了。

思路就是拓扑排序，在排序过程中如果出现circle就停止，如果出现成功也停止。

使用拓扑排序的dfs方法，如果出现访问到父节点的情况，就标记circle，但是在成功情况 的判断上绕了弯路，考虑出度去了，但是其实并不对，dfs的拓扑排序只能通过排序完的结果进行逐个比较得到。


## 拓扑排序

有两种方法可以完成DAG的拓扑排序，分别是dfs和Kahn。
### Kahn算法

其实就是不断的寻找有向图中没有前驱(入度为0)的顶点，将之输出。然后从有向图中删除所有以此顶点为尾的弧。重复操作，直至图空，或者找不到没有前驱的顶点为止。

该算法还可以判断有向图是否存在环(存在环的有向图肯定没有拓扑序列)，通过一个count记录找出的顶点个数，如果少于N则说明存在环使剩余的顶点的入度不为0。（degree数组记录每个点的入度数）
### dfs
本节说明了如何运用深度优先搜索，对一个有向无回路图（dag）进行拓扑排序。对有向无回路图G=(V,E)进行拓扑排序后，结果为该图顶点的一个线性序列，满足如果G包含边（u, v），则在该序列中，u就出现在v的前面（如果图是有回路的，就不可能存在这样的线性序列）。一个图的拓扑排序可以看成是图中所有顶点沿水平线排列而成的一个序列。使得所有的有向边均从左指向右。因此，拓扑排序不同于通常意义上的排序。
