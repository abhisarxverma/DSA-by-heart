# PROBLEM - Given a head node of the linked list, check if the linked list is palindrome and accordingly return True or False.

### ✅ BRUTE FORCE APPROACH - *Using Stack*
---------------------------------------------
- **LOGIC** - *Using a Stack [But we have to before hand know the linked list data type]*
    - Take a stack
    - Traverse the linked list
    - Put the elements in the stack
    - Traverse the linked list again and every time check for the top element in the stack
    - the moment it is not the same, return false
    - At last return true

- **TIME COMPLEXITY** - ***O(2N) First loop to put elements, second loop to compare***
- **SPACE COMPLEXITY** - ***O(N) Stac***

### ✅ BETTER APPROACH - *Using Vector*
---------------------------------------------------------------
- **LOGIC** - *Using a vector*
    - Take a vector
    - Traverse the linked list, put the elements in the vector
    - Then check if the vector is palindrome using the optimal method which takes O(N/2) time
    - In this method we take two pointers one at front and one at back, then loop till front < back and comparing
    - And return according to the result

- **TIME COMPLEXITY** - ***O(N + (N/2)) N for putting the elements in vector and N/2 for checking***
- **SPACE COMPLEXITY** - ***O(N) vector***

### ✅ OPTIMAL APPROACH - *Reversing and comparing*
---------------------------------------------------------------
- **LOGIC** - *Reversing and comparing*
    - Take two node pointer variables `fast` and `slow`
    - First we will get to the middle node of the linked list using the tortoise hare method of moving the `fast` two steps and `slow` one step till the `fast` is null
    - Then we will reverse the linked list after the middle node using the link changing method by taking the front and back
    - Then we will take a `first` and the `second` node pointer and move them simultaneously till the `second` becomes null
    - Why `second`? Cause in case of even length both the linked list will end at same time and in case of odd the `second` will end `first` so we will check till that only
    - And while traversing both we will compare them and if we find not equal then we will return false
    - But before that, we cannot leave the linked list distorted, it's unprofessional, so we will reverse back the linked list after the middle
    - And the linked list will be back to original, you may think that is there not need to joing back the left and the middle ?
    - No, there is no need cause, the left part that is the `middle` has it's next pointed to it's next from starting to end even after reversing, just the linked list after `middle` got reversed and then we reversed it back and that's why there is not need for that
    - And this is also one of the reason that while comparing we go till the second becomes null, cause the `first` is not distorted and it is referencing to the middle's next node all the time.
    - And finally, we will return true;

- **TIME COMPLEXITY** - ***O(N/2 + N/2) = O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>