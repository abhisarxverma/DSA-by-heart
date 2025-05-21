# PROBLEM - Given a Head node of the linked list, return the length of the loop if there exists a loop in the linked list else return 0


### ✅ BRUTE FORCE APPROACH - *Using Vector*
---------------------------------------------
- **LOGIC** - *Using a vector*
    - We will first find the starting node of the loop
    - Take a vector
    - Take a counter varible which will count the total number of nodes we have moved till we found the loop
    - Traverse the linked list
    - Check if the current node is already present in the vector
    - if yes then, the loop length will be the counter - index of the starting node in vector
    - If not, then add the node to the vector and move on
    - Return 0, cause if the loop ends there exists no loop in the linked list.

- **TIME COMPLEXITY** - ***O(N x N) Double looping in vector for every node***
- **SPACE COMPLEXITY** - ***O(N) vector***


### ✅ BETTER APPROACH - *Using set*
---------------------------------------------------------------
- **LOGIC** - *Using a Unordered Map ( O(1) lookup time )*
    - We will first find the starting node of the loop
    - Take a unordered map
    - Take a counter = 0
    - Traverse the linked list
    - check if the node is already in the map
    - if yes return the "counter - node's value in the map"
    - else add the node in the map
    - If the loop gets over return 0, cause there is no loop

- **TIME COMPLEXITY** - ***O(N) Unordered map has O(1) lookup***
- **SPACE COMPLEXITY** - ***O(N) unordered map***


### ✅ OPTIMAL APPROACH - *Tortoise Hare Algorithm*
---------------------------------------------------------------
- **LOGIC** - *TORTOISE HARE APPROACH*
    - Take two node pointer variables front and the back
    - But this time take a counter variable also
    - loop till the front is not null and the front's next is not null
    - While in the loop move the front two steps and move the back one step and update the counter every time
    - If there is a loop they will collide and when they collide, the number of the counter is the loop lenght
    - When the loop exists return 0 cause there is no loop int he linked list

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

<details>
  <summary>🔹 <strong>Why Do Front and the Back Pointer Meet?</strong></summary>
  <ul>
    <li>Think of a running track:</li>
    <li>The slow pointer moves one step at a time.</li>
    <li>The fast pointer moves two steps at a time.</li>
    <li>If there's a loop, the fast pointer will keep moving in circles until it catches up to the slow pointer.</li>
    <li>Since the fast pointer closes the gap with every step, it will eventually meet the slow pointer inside the cycle.</li>
</ul>
</details>

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>