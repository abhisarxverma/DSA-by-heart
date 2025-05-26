# PROBLEM - Given the head node of the linked list, you have to group the nodes at the odd index and the nodes at the even indexes and put the odd ones first and then the evens and return the head of the new linked list.


### ✅ BRUTE FORCE APPROACH - *Using Vector*
---------------------------------------------
- **LOGIC** - *Using the Vector*
    - Take a vector
    - Traverse only the odd index nodes and add them in the vector
    - Traverse only the even index nodes and add them in the vector
    - Traverse the whole linked list again and put the data from the vector to the linked list as the vector is alreay grouped 
    - Cause we first put the data at the odd and then the evens.

- **TIME COMPLEXITY** - ***O(2N) First loop to put the data and second loop to put the grouped data***
- **SPACE COMPLEXITY** - ***O(N) Vector***

### ✅ OPTIMAL APPROACH - *Changing links*
---------------------------------------------------------------
- **LOGIC** - *Linking the odds to odds and evens to evens*
    - Take two node pointers odd and even, and also do not forget to save the even head that we have to link the odd to evens
    - Run a while loop till the even and even's next is not null
    - While in the loop
    - Connect the odd to the odd's next's next
    - Connect the even to the even's next's next
    - Move the odd to it's new next which will also be the odd one cause we have connected it before
    - Move the even to it's new next like odd
    - When the loop get's over, we have grouped the odds and evens but we still need to join them
    - So make the odd's next to the even head that we have saved earlier
    - yes odd will have the last node of the odd group

- **TIME COMPLEXITY** - ***O(N) Single iteration***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>