## PROBLEM - Given a Head Node of the Linked List, return the middle node of the linked list, exact middle in case of odd length and second or latter from the two middle's in case of the even length.

### ✅ BRUTE FORCE APPROACH
-----------------------------
- **LOGIC** - *Get the length first and then go to the middle node*
    - Take a `count` variable to count the length of the linked list
    - Loop from the `head`, to the end of the linked list and update the count.
    - Then loop again `n/2` times, and return the node.

- **TIME COMPLEXITY** - ***O(N+(N/2)) = O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ BETTER APPROACH
-----------------------------
- **LOGIC** - *When the length gets increased by 2 the middle node gets one step forward*
    - Take a `counter` integer
    - Take a `middle` Node and initialize that with `head`
    - Take a `mover` Node and initialize that with hea`d
    - Run a while loop till the mover is not `nullptr` and everytime increment the `counter` by `1`.
    - Also in the loop, if the `counter` becomes even, then move the `middle` node forward to it's next
    - When the loop will get over, you will have your middle node in the `middle` node variable.

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ BETTER APPROACH
-----------------------------
- **LOGIC** - *Tortoise Hare Method*
    - Take a `front` mover Node
    - Take a `back` mover Node
    - Loop till `front` is not `null` and the front's next is not `null`.
    - While in loop, every time
    - Move the `front` node two steps
    - Move the `back` node one step
    - When the loop ends you will have your middle node in the `back` node
    - This works on the same idea that the middle node moves forward one step every time the length of the sequence increases by two.

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***