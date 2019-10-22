# poj1276

## Description

A Bank plans to install a machine for cash withdrawal. The machine is able to deliver appropriate @ bills for a requested cash amount. The machine uses exactly N distinct bill denominations, say Dk, k=1,N, and for each denomination Dk the machine has a supply of nk bills. For example,

N=3, n1=10, D1=100, n2=4, D2=50, n3=5, D3=10

means the machine has a supply of 10 bills of @100 each, 4 bills of @50 each, and 5 bills of @10 each.

Call cash the requested amount of cash the machine should deliver and write a program that computes the maximum amount of cash less than or equal to cash that can be effectively delivered according to the available bill supply of the machine.

Notes:
@ is the symbol of the currency delivered by the machine. For instance, @ may stand for dollar, euro, pound etc.
## Input

The program input is from standard input. Each data set in the input stands for a particular transaction and has the format:

cash N n1 D1 n2 D2 ... nN DN

where 0 <= cash <= 100000 is the amount of cash requested, 0 <=N <= 10 is the number of bill denominations and 0 <= nk <= 1000 is the number of available bills for the Dk denomination, 1 <= Dk <= 1000, k=1,N. White spaces can occur freely between the numbers in the input. The input data are correct.
## Output

For each set of data the program prints the result to the standard output on a separate line as shown in the examples below.

## 解题思路

DP问题，背包问题，递推式为
res[i][j] = max{res[i-1][j], res[i][j-w[i]]+ w[i]}

多重背包可以转为0-1背包，并且用二进制优化解决（把十进制的数用二进制来表示，取任意n个苹果时，只要推出几只箱子就可以了）

我的实现方法就是记录已用的数目，并且进行判断是否会超。