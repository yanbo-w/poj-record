# poj1573
## Description
Description

A robot has been programmed to follow the instructions in its path. Instructions for the next direction the robot is to move are laid down in a grid. The possible instructions are 

N north (up the page) 
S south (down the page) 
E east (to the right on the page) 
W west (to the left on the page) 

For example, suppose the robot starts on the north (top) side of Grid 1 and starts south (down). The path the robot follows is shown. The robot goes through 10 instructions in the grid before leaving the grid. 

Compare what happens in Grid 2: the robot goes through 3 instructions only once, and then starts a loop through 8 instructions, and never exits. 

You are to write a program that determines how long it takes a robot to get out of the grid or how the robot loops around. 

## 解题思路

比较简单的模拟题，主要考虑好边界判断和map数组的读取之间的矛盾。do_while和while基本上一样，主要是移动后不要立即取数组，可能会越界，可以等到下一次循环判断之后再取。
```c++
        while(rows_tr>0 && rows_tr<=rows && columns_tr>0 && columns_tr<=columns){
            if(map[rows_tr-1][columns_tr-1]==0) map[rows_tr-1][columns_tr-1] = steps+1;
            else{
                flag = 1;
                break;
            }
            steps = map[rows_tr-1][columns_tr-1];
```
另外就是c++数组vector等等的初始化还不太熟练，浪费了一些时间。