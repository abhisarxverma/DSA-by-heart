## PROBLEM - Given the head of a linked list and an integer n, rotate the linked list n times and return the head of the new linked list


### ✅ BRUTE FORCE APPROACH - *Using Vector*
----------------------------------------------------------------------------------------------- 
- **LOGIC** - *Using a vector*
    - Take a vector
    - Take a mover node pointer variable
    - Using that mover put all the data of the linked list in the vector
    - rotate that vector n times using the optimal method discussed in the array's section
    - the optimal method to rotate the array was, reverse the portion of array before index of number of times to rotate
    - then reverse the remaining section of the array together as well,
    - then finally reverse the whole array together, you will get your rotated array
    - so we will do this same thing with the array having linked list data
    - After rotating we will put the data from the array back to the linked list
    - and return the head, cause we have just changed the data and not the whole nodes.

- **TIME COMPLEXITY** - ***O(4N) = O(N) [ 2 x O(N) to get and put the data from linked list to array, O(2N) to Reverse the array ]***
- **SPACE COMPLEXITY** - ***O(N) Vector space, Need to optimize this***

### ✅ BETTER APPROACH - *Reversing*
---------------------------------------------------------------
- **LOGIC** - *Using the Reversing, optimal method to rotate arrays directly on linked list.*
    - First we will go the node that is at the position equal to the number of rotations, or you can say the point of rotation
    - We will use the while loop, cause there may be case where the number or rotations is more than the linked list length, then we have to reset the mover to head
    - Now we are at the point of rotation, now we will reverse both the parts one on the left including the point of rotation node and the whole part on the right
    - But before rotating, we have to save the node next to the point of rotation or break point, cause later we have to join the both reversed parts as well
    - We will save that node next to the point or rotation, and then we will make the node next to the point of rotation null
    - Then we will reverse the left part and get the reversed head in leftReversedHead, and we will reverse the right part and save the reversed head in the rightReversedHead
    - Now if you think carefully the head is now the last node of the left reversed section
    - so now to join the two reversed sections we will make the head's next the new rightReversedHead
    - now as we have joined the two reversed parts, we will reverse the whole linked again with leftReversedHead as the input head
    - now we have our answer head.

- **TIME COMPLEXITY** - ***O(2 x length), we are touching every node in linked list***
- **SPACE COMPLEXITY** - ***O(1) Space optimzed***


### ✅ OPTIMAL APPROACH - *Most Simple and optimal*
---------------------------------------------------------------

- **LOGIC** - *Most simple way, make the node next to the point of rotation the head*
    - We will first go the last node of the linked list and join that to the head, making that circular linked list
    - then we will go the node at the point of rotation and make the next node the head
    - and also we cannot forget to make the node at point of rotation's next node null.

- **TIME COMPLEXITY** - ***O(Length) we are visiting every node***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace; margin-top: 70px;">
    <h1>THANK YOU!</h1>
</div>