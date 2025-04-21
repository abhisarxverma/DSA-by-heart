from typing import List

# PROBLEM - Given an array, find the number which appears more than one-third of the size of the array

'''
 EXAMPLE INPUT - 2, 5, 2, 9, 2, 1
 EXAMPLE OUTPUT - 2
'''

'''
Brute Approach
---------------------
LOGIC - Loop over every element and then loop over the array again to get the count of the number of the outer loop
if the count is greater than the one-third of the array then return else pass. and if the majority element is not there
return -1

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def majority_element_3_brute( array : List[int] ):
    n = len(array)
    res = []
    for num in array:
        count = 0
        for num2 in array:
            if num2 == num: count+=1
            if count >= (n/3)+1:
                if not res: res.append(num)
                else:
                    if num not in res:
                        res.append(num)

    return res

'''
Better Approach
---------------------
LOGIC - Use a hashmap as a count storer, while iterating update the count in the hashmap and if the count
is greater than one-third of the size of the array return the number

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
'''

def majority_element_3_better( array : List[int] ):
    n = len(array)
    counter = dict()
    res = []
    for num in array:
        counter[num] = counter.get(num, 0) + 1
        if counter[num] >= (n/3)+1: 
            if not res: res.append(num)
            else : 
                if num != res[-1]: res.append(num)

    return res

'''
Optimal Approach - BOYRE - MOORE'S VOTING ALGORITHM
-----------------------------------------------------
LOGIC - If you think carefully, you will see that there cannot exit more than 2 majority element 
if you want the count of the majority element to be more than one - third. so Unlike the normal 
boyre-moore's voting algorithm, this time take two variables as numbers and do the same as the normal
algorithm, increment if you find the same number and decrement if you find the different number
at last you should have the two majority elements in your two variables.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def majority_element_3_optimal( array : List[int] ):
    n = len(array)
    number1 = float("-inf")
    number2 = float("-inf")
    count1 = 0
    count2 = 0

    for num in array:
        if count1 == 0 and num != number2:
            number1 = num
            count1+=1
        elif count2 == 0 and num != number1:
            number2 = num
            count2+=1
        if num == number1: count1+=1
        elif num == number2 : count2+=1
        else: 
            count1-=1
            count2-=1

    count1 = 0
    count2 = 0
    for num in array:
        if num == number1: count1+=1
        elif num == number2: count2+=1

    target = (n/3)+1
    if count1 >= target and count2 >= target:
        return [number1, number2]

    return [-1, -1]

arr = [2, 2, 5, 5, 2, 5, 9, 5, 2]
majority_elements = majority_element_3_brute(arr)
print(f"Majority elements : {majority_elements}")
