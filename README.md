# push_swap

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)![Denny's 42Project Score](https://img.shields.io/badge/Success-86%2F100-brightgreen)

## Description

This project is about sorting data on a stack. The success rely on choosing the right algorithm for an optmized data sort.

## Goals

Write a program in C which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received

## Mandatory

The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.

To do this you have the following operations at your disposal:

```
sa  : swap a - swap the first 2 elements at the top of stack a.
sb  : swap b - swap the first 2 elements at the top of stack b.
ss  : sa and sb at the same time.
pa  : push a - take the first element at the top of b and put it at the top of a.
pb  : push b - take the first element at the top of a and put it at the top of b.
ra  : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb  : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr  : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
```

## Bonus

• Write a program named checker, which will get as an argument the stack ``a`` formatted as a list of integers. The first argument should be at the top of the stack. If no argument is given checker stops and displays nothing

• If after executing those instructions, stack ``a`` is actually sorted and ``b`` is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every other case, checker must display "KO" followed by a ’\n’ on the standard output.


## Usage

### MANDATORY

To compile the program, run:

```
$ make
```

Execute the program providing the number stack as follows:

```
$ ./push_swap 5 1 4 2 3
```

The program will return the list of actions needed to sort the provided stack:

```
ra
pb
sa
pb
sa
pb
pa
pa
pa
```


### BONUS

Execute the checker program with the same arguments, followed by the actions returned by push_swap, followed by ``CTRL + D``

```
$ ./checker 5 1 4 2 3
ra
pb
sa
pb
sa
pb
pa
pa
pa
```

The checker then, will evaluate if the provided actions did sort the stack or not:

```
OK
```

## Algorithm

I used merge sort algorithm for most part, but limited to a few chunks of the original stack. The amount of chunks is related to the size of the stack.

This implementation scored 86/100.

You can check the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) for this solution.

![Push_swap_Visualizer](https://github.com/dpiza/resources/blob/master/gifs/merge_sort_simple_selection.gif?raw=true)

## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)