from typing import List

'''
 PROBLEM - Given an array of array intervals of integers, merge the intervals.

 EXAMPLE INPUT - {{1, 3}, {2, 6}, {8, 10}, {9, 12}}
 EXAMPLE OUTPUT - { {1, 6}, {8, 12} }
'''

'''
Brute Approach
---------------------
LOGIC - Take a set to store the unique intervals, Loop over the intervals , take two variables, low and high, and initialize them to the first and second element
loop over the array again and check if the current interval of low and high is streched more on either side, and according to 
that update the low and high of the interval, and on completion of the second loop, we will have the interval is unique, add that 
to the unique intervals set, and repeat the process.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(N) set
'''

def merge_overlapping_subintervals_brute( intervals : List[List[int]] ):
    n = len(intervals)
    merged_uniques = set()
    for i in range(n):
        low = intervals[i][0]
        high = intervals[i][1]
        for j in range(n):
            if i == j : continue
            if intervals[j][0] >= low and intervals[j][0] <= high:  # if the current interval's low is in the range of the low and high interval then this can expand the interval more from right side
                if intervals[j][1] > high : high = intervals[j][1]  # check and update the high
            if intervals[j][1] >= low and intervals[j][1] <= high:  # // if the current intervals' high is in the range of the low and high interval then this can expand the interval more from left side
                if intervals[j][0] < low : low = intervals[j][0]    # check and update the low
        merged_uniques.add((low, high))

    return list[merged_uniques]

'''
Optimal Approach
---------------------
LOGIC - Sort the intervals array, take two variables, low and high, and while looping update them, increase the high if the low of the
current interval is under the low and high variables and high is greater than the high variable, and decrease the low if the high of the 
current interval falls under the interval made by the low and high variable and the low is shorter than the low variable.

TIME COMPLEXITY - O(N + NlogN) Single iteration
SPACE COMPLEXITY - O(1)
'''

def merge_overlapping_subintervals_optimal( intervals : List[List[int]] ):
    n = len(intervals)
    merged = []
    low = intervals[0][0]
    high = intervals[0][1]
    for i in range(1, n):
        if intervals[i][0] >= low and intervals[i][0] <= high:
            if intervals[i][1] > high: high = intervals[i][1]
        else:
            merged.append((low, high))
            low = intervals[i][0]
            high = intervals[i][1]
        
    merged.append((low, high))
    return merged

intervals = [[1, 3], [2, 6], [8, 10], [9, 12]];
merged = merge_overlapping_subintervals_optimal(intervals)
print(merged)