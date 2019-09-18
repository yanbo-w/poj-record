# poj3026

## Description

The Borg is an immensely powerful race of enhanced humanoids from the delta quadrant of the galaxy. The Borg collective is the term used to describe the group consciousness of the Borg civilization. Each Borg individual is linked to the collective by a sophisticated subspace network that insures each member is given constant supervision and guidance.

Your task is to help the Borg (yes, really) by developing a program which helps the Borg to estimate the minimal cost of scanning a maze for the assimilation of aliens hiding in the maze, by moving in north, west, east, and south steps. The tricky thing is that the beginning of the search is conducted by a large group of over 100 individuals. Whenever an alien is assimilated, or at the beginning of the search, the group may split in two or more groups (but their consciousness is still collective.). The cost of searching a maze is definied as the total distance covered by all the groups involved in the search together. That is, if the original group walks five steps, then splits into two groups each walking three steps, the total distance is 11=5+3+3.
## Input

On the first line of input there is one integer, N <= 50, giving the number of test cases in the input. Each test case starts with a line containg two integers x, y such that 1 <= x,y <= 50. After this, y lines follow, each which x characters. For each character, a space `` '' stands for an open space, a hash mark ``#'' stands for an obstructing wall, the capital letter ``A'' stand for an alien, and the capital letter ``S'' stands for the start of the search. The perimeter of the maze is always closed, i.e., there is no way to get out from the coordinate of the ``S''. At most 100 aliens are present in the maze, and everyone is reachable.
## Output

For every test case, output one line containing the minimal cost of a succesful search of the maze leaving no aliens alive.

## 解题思路

最开始思路是这其实是一个最小生成树问题，求点点之间的距离用bfs实现。

最开始bfs写成了dfs，导致结果有问题，然后改成了bfs之后跑通。

bfs的判断也是一个问题，到底哪一步判断在哪里，也需要斟酌，最好不要直接码，需要先手写然后码。

其次，出现了RE的情况，因为node数组开小了，所以出问题了，node可能数目不是N，而是N^2。