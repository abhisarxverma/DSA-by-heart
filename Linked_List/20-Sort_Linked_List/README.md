# PROBLEM - Given the head node of the linked list, sort the linked list and return the head of the sorted linked list



### ✅ BRUTE FORCE APPROACH - *Using Vector*
---------------------------------------------
- **LOGIC** - *Using Vector [ But for this approach, we have to byhand know the datatype of the linked list ]*
    - Take the data of the linked list into the vector
    - Sort the vector using the Merge sort 
    - Then put the sorted vector's data back to the linked list
    - return the head

- **TIME COMPLEXITY** - ***O(N) To put data into vector + O(N Log N) Merge Sort + O(N) put the sorted data back into the linked list***
- **SPACE COMPLEXITY** - ***O(N)***

### ✅ BETTER APPROACH - *Selection Sort*
---------------------------------------------------------------
- **LOGIC** - *Selection sort [Iterate linked list and for every iteration find the smallest node after that node, then swap the data of the two]*
    - Take a First node pointer variable
    - Move the first node pointer til the end of the linked list
    - In that loop every time,
    - Take a min node pointer variable, which will hold the minimum value node in the linked list after the first
    - Move from the next of the first to the end of the linked list and update the min if you find any node smaller than the min
    - at last swap the data of the first and the min node
    - move the first to it's next
    - at the end of the loop return the head.

- **TIME COMPLEXITY** - ***O(N) X O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

### ✅ OPTIMAL APPROACH - *Merge Sort*
---------------------------------------------------------------
- **LOGIC** - *MergeSort [ Using recursion divide the list into two halfes and sort the two sorted list ]*
    - First we have to make a get_middle function to get the exact middle of the linked list as in the mergesort we have to divide the list into two
    - We will use the tortoise hare method to find the middle, but one catch here is that we will take the first middle in case of the even length linked list 
    - and that's why in the getmiddle we will move the fast one node from starting cause the tortoise hare gives the second middle in the even length linked list
    - Now we have to code the merge function for the linked list
    - This will be simple take a dummy node cause this will help to join the next node while merging easily
    - but we cannot just start to move the dummy node straight cause at last we have to return the head of the merged sorted linked list and in doing so, we will lose the head
    - so we will take another k node and initialze that with the dummy node and while merging we will join the next node to k and then move the k also to it's next
    - and after performing the traditional merging  process we will return the dummy's next node cause that's where our merged sorted linked list starts
    - New we have our merge function ready, now we just have to code a function mergesort that will recursively divide the linked list into two till there exist one node in each of the side and then perform the merge operation on both
    - So as the mergesort function is recursive we have to put a base case to stop the division, and that will be single node in the linked list, cause logically we cannot divide single node linked list
    - then we will use the getmiddle function to get the middle of the linked list in the middle node pointer variable
    - now to make the further division, we have to pass the head of two divided linked lists again to the mergesort function
    - so we will again run the mergesort function with the head as argument cause the current head is the head of the left part of the linked list and we will take the result in the left variable
    - also we will again run the mergesort function with the middle's next as argument cause middle's next will be start of the right side of the linked list and we will take the result in the right variable
    - now recursively we are at the end of the division with single nodes in both the linked list
    - now we have to merge the left and right and return that merged linked list to the upper recursive stack cause this merged linked list is maybe the left or the right and it also have to be merged with other merged sorted linked list
    - so this was it thank you for reading and now we have our sorted linked list with the optimal time and space complexity

- **TIME COMPLEXITY** - ***O(N) Finding middle every time + O(N LogN) Merge sort = O(2N Log N)***
- **SPACE COMPLEXITY** - ***O(N) Recursive call stack***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>