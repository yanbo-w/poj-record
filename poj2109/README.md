# Poj2109
Tags：贪心算法 大数运算
## Description
Current work in cryptography involves (among other things) large prime numbers and computing powers of numbers among these primes. Work in this area has resulted in the practical use of results from number theory and other branches of mathematics once considered to be only of theoretical interest. 
This problem involves the efficient computation of integer roots of numbers. 
Given an integer n>=1 and an integer p>= 1 you have to write a program that determines the n th positive root of p. In this problem, given such integers n and p, p will always be of the form k to the nth. power, for an integer k (this integer is what your program must find).
## Input
The input consists of a sequence of integer pairs n and p with each integer on a line by itself. For all such pairs 1<=n<= 200, 1<=p<10101 and there exists an integer k, 1<=k<=109 such that kn = p.
## Output

For each integer pair n and p the value k should be printed, i.e., the number k such that k n =p.

## 思路
刚开始没有思路，感觉这题目怎么和贪心算法扯上关系了，然后打开discuss区一看，一派其乐融融的景象，大家都在说一句话AC，感叹出题者水的一匹。试了一下果然一次AC了。。。。先提交一版。

## Formal Solution

看到discuss区里面有两种说法，一种是二分，一种是按位数贪心。

## Hint
1. cin函数是有输出的判断的，和scanf一样，如果达到输入结尾就会输出false，及while(cin >> x)是可以用来判断输入的；

