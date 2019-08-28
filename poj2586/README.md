# poj2586
## Description
Accounting for Computer Machinists (ACM) has sufferred from the Y2K bug and lost some vital data for preparing annual report for MS Inc. 
All what they remember is that MS Inc. posted a surplus or a deficit each month of 1999 and each month when MS Inc. posted surplus, the amount of surplus was s and each month when MS Inc. posted deficit, the deficit was d. They do not remember which or how many months posted surplus or deficit. MS Inc., unlike other companies, posts their earnings for each consecutive 5 months during a year. ACM knows that each of these 8 postings reported a deficit but they do not know how much. The chief accountant is almost sure that MS Inc. was about to post surplus for the entire year of 1999. Almost but not quite. 

Write a program, which decides whether MS Inc. suffered a deficit during 1999, or if a surplus for 1999 was possible, what is the maximum amount of surplus that they can post.

## 解题思路
水题，主要是题意能够读清楚，就是一个每5月亏损的限定条件，加上全年12个月多出来的两个月的可变因素，最终最优化总收益的过程。
分开来看，1-5，6-10分别是两个亏损的条件限定，所以最大的收益是一定的，并且如果1-5和6-10的排列一样，根据周期性就能确定其他月份都满足了，但是为了让全年的收益最大，就要让11，12两个月的收益最大，这样就决定了这两个月是尽量要盈利的也就是在1-5，6-10之中前2位的盈利最大，这样就可以确定出1-5和6-10的分布，从而得到最终的结果。

