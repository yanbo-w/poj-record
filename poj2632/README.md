# poj2632
## Description
In a modernized warehouse, robots are used to fetch the goods. Careful planning is needed to ensure that the robots reach their destinations without crashing into each other. Of course, all warehouses are rectangular, and all robots occupy a circular floor space with a diameter of 1 meter. Assume there are N robots, numbered from 1 through N. You will get to know the position and orientation of each robot, and all the instructions, which are carefully (and mindlessly) followed by the robots. Instructions are processed in the order they come. No two robots move simultaneously; a robot always completes its move before the next one starts moving. 
A robot crashes with a wall if it attempts to move outside the area of the warehouse, and two robots crash with each other if they ever try to occupy the same spot.

## 解题思路

模拟题，没有什么数学技巧，主要就是编程熟练度。

首先编程过程中出现的问题包括：
- 函数返回值为数组情况下的初始化和处理
- 负数取mod的值处理

其次，得了一次WA，主要原因在于判断碰撞的时候，没有考虑清楚充要条件，不够仔细，其实是要判断最先撞到的情况的，因此要做一个最小距离的比较。
```c++
if(robo_y[robo_num_tr]>=robo_y[robo_num] && robo_y[robo_num_tr]<=robo_y_prev){
                                        crash_distance = robo_y_prev-robo_y[robo_num_tr];
                                        res[2] = robo_num_tr;
                                    }
```

代码还不够简洁，还有改进的空间。