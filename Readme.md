# MultithreadedAlgebra

Unique approach to solve algebric problem with help of threading.
If you want to explore start from [`calculate.h`](https://github.com/rational-kunal/multithreaded_algebra/blob/master/calculate.h)

> Created in third year as a mini project, just for fun and to explore pthread. This is in no way completely efficient.

## How does it work

My first assumption while designing was that the expression will be of form`([expression][operator][expression])`.
So, I can evaluate left expression and right expression seperatly in seperate thread and join that to evaluate main expression.

## How to use

Use function `long int calculate(char [])` from [`calculate.h`](https://link).
It requires expression in string format and it returns evaluation of that expression.
For examples, see [`test.h`](https://github.com/rational-kunal/multithreaded_algebra/blob/master/test.c)