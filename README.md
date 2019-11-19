# push_swap
**Push_swap** is a highly effective algorithm project (School 21). We need to sort data which is represented as a set of integer values. There are 2 stacks and a set of instructions to manipulate both stacks.

The goal is to sort numbers (duplicates are not allowed) into a stack in ascending order using only the following operations:

- **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- **ss** : sa and sb at the same time.
- **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr** : rra and rrb at the same time.
## Usage
>The **push_swap** program displays the smallest list of instructions possible to sort the stack.

>The **checker** program checks whether "push_swap" sorts the stack correctly.

To compile the programs go to the project's directory and run ```make``` or ```make all```.

To get a list of instructions run **push_swap**:
```
./push_swap 98 21 76 43 12 67 34 89
```
To check that list run **push_swap** whith **checker**:
```
ARG="98 21 76 43 12 67 34 89"; ./push_swap $ARG | ./checker $ARG
```
To use visualisation use **checker** with **-c -v**:
```
ARG="-10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 10 9 8 7 6 5 4 3 2 1"; ./push_swap $ARG | ./checker -c -v $ARG
```
