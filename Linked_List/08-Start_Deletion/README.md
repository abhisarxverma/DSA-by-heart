# PROBLEM - Given a Head node, delete the first node and return the new head.


### ✅ APPROACH
---------------

- **LOGIC** - 
    - We will save the `head` in another varaible, cause if we directly move the `head` forward, then there will be memory leak.
    - After saving, then move the `head` forward
    - Free the space of the previous `head`
    return new `head`

- **TIME COMPLEXITY** - ***O(1)***
- **SPACE COMPLEXITY** - ***O(1)***