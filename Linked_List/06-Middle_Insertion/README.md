## PROBLEM - Given a Head and an integer number and an interger position, insert the number at the given position in the lined list, and return the head of the new linked list, in case of error, print error message and return the head.

### ✅ APPROACH
---------------
- **LOGIC** - *(Explaination is long but the code is small)*
    - To insert a number at the given position, we will go to one node before the node at that position, but, before that,
    - Check if the head passed is null, if yes, then this means that the linked list is empty, return the null.
    - Check if the position entered is smaller to zero, if yes, print error message and return the `head`
    - And also cause in this approach we are going to the one node before the position to insert, if the user enter the `1`, then this approach may fail, so handle that case seperately.
    - Take a `mover` pointer variable, move the `mover` forward using a for loop running "`position - 2`" times
    - Add a check in the for loop that if the `mover` becomes `none` print the error message if you want and return `head`, cause the user may enter the position which is more than the linked list size.
    - When the for loop finishes we will be at the one position before the position we want to insert new number
    - But we have to check here again, cause if the user enters the position which is 2 greater than the linked list size, the mover will become null but not in for loop, but after that.
    - And then make a `new node` with the data equal to the number given, make the new node's `next` the mover's `next` and make the mover's `next` the new node
    return the `head`

- **TIME COMPLEXITY** - ***O(Size of Array)***
- **SPACE COMPLEXITY** - ***O(1)***