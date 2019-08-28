# poj3295
## Description
WFF 'N PROOF is a logic game played with dice. Each die has six faces representing some subset of the possible symbols K, A, N, C, E, p, q, r, s, t. A Well-formed formula (WFF) is any string of these symbols obeying the following rules:

p, q, r, s, and t are WFFs
if w is a WFF, Nw is a WFF
if w and x are WFFs, Kwx, Awx, Cwx, and Ewx are WFFs.
The meaning of a WFF is defined as follows:
p, q, r, s, and t are logical variables that may take on the value 0 (false) or 1 (true).
K, A, N, C, E mean and, or, not, implies, and equals as defined in the truth table below.
Definitions of K, A, N, C, and E
     w  x	  Kwx	  Awx	   Nw	  Cwx	  Ewx
  1  1	  1	  1	   0	  1	  1
  1  0	  0	  1	   0	  0	  0
  0  1	  0	  1	   1	  1	  0
  0  0	  0	  0	   1	  1	  1
A tautology is a WFF that has value 1 (true) regardless of the values of its variables. For example, ApNp is a tautology because it is true regardless of the value of p. On the other hand, ApNq is not, because it has the value 0 for p=0, q=1.

You must determine whether or not a WFF is a tautology.

## 解题思路
一道判断永真式的题目，主要是利用堆栈进行因式分解，和离散数学中学的差不多。
最开始思考的时候，考虑到式中可能出现的情况可能会有n个数字，所以担心复杂度O(2^n)太大，想通过别的思路来做，发现没有特别好的方法，后来自己审题，其实是常数种情况，也就是2^5，所以利用穷举法做没有什么问题。
