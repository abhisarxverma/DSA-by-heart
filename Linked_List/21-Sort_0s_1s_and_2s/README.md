# PROBLEM - Given the head node of the linked list which have numbers 0s, 1s and 2s, sort the linked list and return the head of the sorted linked list.


### ✅ BRUTE FORCE APPROACH - *Using Vector*
---------------------------------------------
- **LOGIC** - *Using Vector*
    - Take all the data of the linked list in an array
    - Sort the array then put the data back in the linked list.

- **TIME COMPLEXITY** - ***(3N log N) - O(N) to put the data in array + O(N Log N) Sorting + O(N) To put the data back in linked list***
- **SPACE COMPLEXITY** - ***O(N) array***

### ✅ BETTER APPROACH - *Selection Sort*
---------------------------------------------------------------
- **LOGIC** - *Counting the occurences*
    - Traverse the linked list
    - While traversing update the count of the 0s 1s and 2s
    - after getting count traverse the linked list again putting the values according to the occurences
    - return the head

- **TIME COMPLEXITY** - ***O(2N) - O(N) To get the counts + O(N) To put the data in sorted way***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ OPTIMAL APPROACH - *Merge Sort*
---------------------------------------------------------------
- **LOGIC** - *Taking three seperate linked list and joining them.*
    1. Create Three Dummy Nodes
        One dummy node each for:
        0s list
        1s list
        2s list
        Let’s call them:
        zeroHead, oneHead, twoHead
        Initialize each with a dummy value (e.g., -1 or any placeholder)
        These dummy nodes make list handling easy and clean.

    2. Create Three Tails (Moving Pointers)
        These will help us append elements to the correct list:
        zeroTail, oneTail, twoTail
        Initially, point them to their respective dummy nodes.

    3. Traverse Original Linked List
        For each node in the list:
        If it's 0: append it to the 0s list using zeroTail
        If it's 1: append to the 1s list
        If it's 2: append to the 2s list
        After appending, move the corresponding tail forward.

    4. Link the Three Lists
        We now have:
        A dummy-headed list of 0s
        A dummy-headed list of 1s
        A dummy-headed list of 2s

    Now we join them:
        Set twoTail->next = nullptr to avoid loops.
        Join:
        oneTail->next = twoHead->next (skip dummy)
        Join:
        zeroTail->next = oneHead->next (or twoHead->next if 1s list is empty)
        🧠 What If Some Lists Are Empty?
        If 1s are missing:
        oneTail == oneHead → .next will point directly to 2s
        If 0s are missing:
        zeroTail == zeroHead → .next will point to 1s or 2s
        This chain ensures the result is always correct.

- **TIME COMPLEXITY** - O(2N) - O(N) To get the counts + O(N) To put the data in sorted way
- **SPACE COMPLEXITY** - O(1)

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>