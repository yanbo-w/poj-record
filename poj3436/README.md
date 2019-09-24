# poj3436
## Description

As you know, all the computers used for ACM contests must be identical, so the participants compete on equal terms. That is why all these computers are historically produced at the same factory.

Every ACM computer consists of P parts. When all these parts are present, the computer is ready and can be shipped to one of the numerous ACM contests.

Computer manufacturing is fully automated by using N various machines. Each machine removes some parts from a half-finished computer and adds some new parts (removing of parts is sometimes necessary as the parts cannot be added to a computer in arbitrary order). Each machine is described by its performance (measured in computers per hour), input and output specification.

Input specification describes which parts must be present in a half-finished computer for the machine to be able to operate on it. The specification is a set of P numbers 0, 1 or 2 (one number for each part), where 0 means that corresponding part must not be present, 1 — the part is required, 2 — presence of the part doesn't matter.

Output specification describes the result of the operation, and is a set of P numbers 0 or 1, where 0 means that the part is absent, 1 — the part is present.

The machines are connected by very fast production lines so that delivery time is negligibly small compared to production time.

After many years of operation the overall performance of the ACM Computer Factory became insufficient for satisfying the growing contest needs. That is why ACM directorate decided to upgrade the factory.

As different machines were installed in different time periods, they were often not optimally connected to the existing factory machines. It was noted that the easiest way to upgrade the factory is to rearrange production lines. ACM directorate decided to entrust you with solving this problem.

## Input

Input file contains integers P N, then N descriptions of the machines. The description of ith machine is represented as by 2 P + 1 integers Qi Si,1 Si,2...Si,P Di,1 Di,2...Di,P, where Qi specifies performance, Si,j — input specification for part j, Di,k — output specification for part k.

Constraints

1 ≤ P ≤ 10, 1 ≤ N ≤ 50, 1 ≤ Qi ≤ 10000

## Output

Output the maximum possible overall performance, then M — number of connections that must be made, then M descriptions of the connections. Each connection between machines A and B must be described by three positive numbers A B W, where W is the number of computers delivered from A to B per hour.

If several solutions exist, output any of them.

## 考点

最大流算法；
拆点；

## 解题过程

最开始想的比较简单，没有考虑到增广路径的核心就是可以反悔，直接用顶点的Q值来作为bfs的条件，后来发现这样完全不行。

然后用了拆点的方法进行计算，得到了比较好的结果。

有一点问题值得一错，就是connection的计算不能在计算过程中算，这样会把反悔的也算进去了。

另外就是多源点的情况可以设置超级源点和超级汇点来计算。

拆点拆点！！！！！

反悔反悔！！！！！