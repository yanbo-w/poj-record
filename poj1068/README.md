# poj1068
## Description
Let S = s1 s2...s2n be a well-formed string of parentheses. S can be encoded in two different ways: 
q	By an integer sequence P = p1 p2...pn where pi is the number of left parentheses before the ith right parenthesis in S (P-sequence). 
q	By an integer sequence W = w1 w2...wn where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence). 

Following is an example of the above encodings: 

	S		(((()()())))

	P-sequence	    4 5 6666

	W-sequence	    1 1 1456


Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string. 

## 解题思路

水题。。。怎么这么多，就是判断括号的问题，最开始想到的是用栈实现，但是其实没有必要。

在discuss中看到一个精简版的，分析了一下思路：

将P中值相同的分成一类，在每一类集合代表该类中的右括号之前有X个左括号，由于P中数字是递增的，所以X也是递增的。

设立数组a，a[i]=k表示左边有i个左括号的右括号集合已经消耗了从右向左数（因为是就近匹配）的k个括号。

每读入p的一个新数字m，它要么

1. 比上一个大：则意味着产生了新集合，且a[m]=1，并总输出1.

2. 更上一个一样大：意味着在上一个集合上新增一个元素，那么要寻找相匹配的左括号，首先要跳过该类消耗的括号数a[m]，则还剩余m-a[m]个左括号，这些括号也不是都可以用的，因为此时m-a[m]集合也有消耗，所以要减去集合消耗的，再往前递推，一直到a[k]=0，表明该处可以匹配。把记录下跳过的左括号数（即已经被消耗的）+1就是该右括号要输出的结果，同时也要更新a[m]为这个值。

说了这么多，精髓代码才5L。代码如下，以后还要多多体会
 ———————————————— 
版权声明：本文为CSDN博主「mtawaken」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/mtawaken/article/details/7354242
