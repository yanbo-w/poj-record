# poj1837
## Description

Gigel has a strange "balance" and he wants to poise it. Actually, the device is different from any other ordinary balance.
It orders two arms of negligible weight and each arm's length is 15. Some hooks are attached to these arms and Gigel wants to hang up some weights from his collection of G weights (1 <= G <= 20) knowing that these weights have distinct values in the range 1..25. Gigel may droop any weight of any hook but he is forced to use all the weights.
Finally, Gigel managed to balance the device using the experience he gained at the National Olympiad in Informatics. Now he would like to know in how many ways the device can be balanced.

Knowing the repartition of the hooks and the set of the weights write a program that calculates the number of possibilities to balance the device.
It is guaranteed that will exist at least one solution for each test case at the evaluation.
## Input

The input has the following structure:
• the first line contains the number C (2 <= C <= 20) and the number G (2 <= G <= 20);
• the next line contains C integer numbers (these numbers are also distinct and sorted in ascending order) in the range -15..15 representing the repartition of the hooks; each number represents the position relative to the center of the balance on the X axis (when no weights are attached the device is balanced and lined up to the X axis; the absolute value of the distances represents the distance between the hook and the balance center and the sign of the numbers determines the arm of the balance to which the hook is attached: '-' for the left arm and '+' for the right arm);
• on the next line there are G natural, distinct and sorted in ascending order numbers in the range 1..25 representing the weights' values.
## Output

The output contains the number M representing the number of possibilities to poise the balance.

## 解题思路

背包DP问题，最开始没有思路，借鉴了其他人的思路。

其实DP问题主要就是两点，一个是最优子结构，另外一个就是重复子问题。

这个题目是有重复子问题的，因为达到某一个平衡状态的时候是有可能有多种情况的。

子问题主要在于每次添加一个新的砝码，达到一个新的状态，最优子结构也要有最优的传递目标，在这里就是总的类别。

背包问题虽然看似计算了很多，把0-总物品数以及0-总容量都计算了一遍，但其实是减少了很多重复的计算的。