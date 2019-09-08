# poj2253

## Description

Freddy Frog is sitting on a stone in the middle of a lake. Suddenly he notices Fiona Frog who is sitting on another stone. He plans to visit her, but since the water is dirty and full of tourists' sunscreen, he wants to avoid swimming and instead reach her by jumping.
Unfortunately Fiona's stone is out of his jump range. Therefore Freddy considers to use other stones as intermediate stops and reach her by a sequence of several small jumps.
To execute a given sequence of jumps, a frog's jump range obviously must be at least as long as the longest jump occuring in the sequence.
The frog distance (humans also call it minimax distance) between two stones therefore is defined as the minimum necessary jump range over all possible paths between the two stones.

You are given the coordinates of Freddy's stone, Fiona's stone and all other stones in the lake. Your job is to compute the frog distance between Freddy's and Fiona's stone.
## Input

The input will contain one or more test cases. The first line of each test case will contain the number of stones n (2<=n<=200). The next n lines each contain two integers xi,yi (0 <= xi,yi <= 1000) representing the coordinates of stone #i. Stone #1 is Freddy's stone, stone #2 is Fiona's stone, the other n-2 stones are unoccupied. There's a blank line following each test case. Input is terminated by a value of zero (0) for n.
## Output

For each test case, print a line saying "Scenario #x" and a line saying "Frog Distance = y" where x is replaced by the test case number (they are numbered from 1) and y is replaced by the appropriate real number, printed to three decimals. Put a blank line after each test case, even after the last one.

## 解题思路

最短路径问题的变体，最开始考虑使用floyd算法进行计算，但是只进行了两点作为锚点的松弛，显然不对，之后用floyd进行AC。

评论区中发现有大概几种解法，一个是PRIM算法和Krustal，最小生成树算法的变形。另外一种是dijkstra， floyd， spfa（bellman优化）的变形，都可以解决该问题。

松弛条件是road = min(road[i][j], max(road[i][k], road[k][j]));