# poj1789

## Description

Advanced Cargo Movement, Ltd. uses trucks of different types. Some trucks are used for vegetable delivery, other for furniture, or for bricks. The company has its own code describing each type of a truck. The code is simply a string of exactly seven lowercase letters (each letter on each position has a very special meaning but that is unimportant for this task). At the beginning of company's history, just a single truck type was used but later other types were derived from it, then from the new types another types were derived, and so on.

Today, ACM is rich enough to pay historians to study its history. One thing historians tried to find out is so called derivation plan -- i.e. how the truck types were derived. They defined the distance of truck types as the number of positions with different letters in truck type codes. They also assumed that each truck type was derived from exactly one other truck type (except for the first truck type which was not derived from any other type). The quality of a derivation plan was then defined as
1/Σ(to,td)d(to,td)

where the sum goes over all pairs of types in the derivation plan such that to is the original type and td the type derived from it and d(to,td) is the distance of the types.
Since historians failed, you are to write a program to help them. Given the codes of truck types, your program should find the highest possible quality of a derivation plan.
## Input

The input consists of several test cases. Each test case begins with a line containing the number of truck types, N, 2 <= N <= 2 000. Each of the following N lines of input contains one truck type code (a string of seven lowercase letters). You may assume that the codes uniquely describe the trucks, i.e., no two of these N lines are the same. The input is terminated with zero at the place of number of truck types.
## Output

For each test case, your program should output the text "The highest possible quality is 1/Q.", where 1/Q is the quality of the best derivation plan.

## 解题过程

这算是稠密图，所以使用prim算法，但是没有用heap堆。最开始每一次都重新遍历所有的边，找安全边，但是后来发现没有必要，直接维护一个key就可以了。

在过程中多次TLE，后来发现是cin和string的速度比较慢，换了scanf就好了。

下次试一试用heap再优化一下。