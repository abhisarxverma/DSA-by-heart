# PROBLEM - 
Given the array of integers representing the number of the day on which the floor bloomed.
Find the minimum number of days that is required to make m bouqet of the k flowers 
given that you will make one bouqet from the contiguous days,

### Example Input - [7, 3, 9, 5, 8], Bouqets = 3, Flowers_per_bouqet = 1
### Example Output - 7

## ✅ Brute Force Approach
- **LOGIC** - Linear Search - 
    - Loop from the minimum to the maximum in the array,
    - Have a helper function that can on giving the array, the day number and the number of the flowers we need, can tell us that we are able to make the bouque or not.
    - As we are looping from the minimum to the maximum, the first time we find any number that can give us more than or equal to the number of bouqets we need, we will return that. 

- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - Binary search - 
    - We here do not know that the array of the bloom days is sorted or not
    - But know for sure that our answer will lie in between the min and the max day in the array which is indeed sorted
    So we can easily do the binary search and get our answer
    - So here we just have to apply the floor finding method of the binary search which we have done earlier.
    - We will take mid and check if the number of bouqets it gives is greater than or equal to the number of bouqets we need using a helper function that we have coded in the brute force approach
    - If yes then we will do the high = mid, we will not discard the mid also cause that can be the answer
    - And If no then simply do the low = mid+1

- **TIME COMPLEXITY** - ***O(Log N)***
- **SPACE COMPLEXITY** - ***O(1)***