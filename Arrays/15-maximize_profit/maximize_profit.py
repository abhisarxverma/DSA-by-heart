from typing import List

# PROBLEM - Given an array of prices, give the maximum profit that we can get if we buy and then sell. 

'''
Brute Force Approach
---------------------
LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum difference
and return the greatest.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
'''

def maximize_profit_brute( prices : List[int] ):
    n = len(prices)
    final_res = []
    final_profit = float("-inf")
    for i in range(n):
        for j in range(i+1, n):
            profit = prices[j] - prices[i]
            if profit > final_profit:
                final_profit = profit
                final_res = [i, j]
    return final_res

'''
Better Approach
---------------------
LOGIC - If you think carefully, we just have to find the difference between the minimum and the maximum 
or maybe their indexes. So, while iterating, keep track of the minimum number before it and update the final
profit based on the difference.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def maximize_profit_better( prices : List[int] ):
    n = len(prices)
    final_res = []
    min = prices[0]
    final_profit = float("-inf")
    for num in prices[1:]:
        profit = num - min
        if profit > final_profit:
            final_profit = profit
            final_res = [min, num]
        if num < min: min = num
    return final_res


prices = [7, 1, 5, 3, 6, 4]
ans = maximize_profit_better(prices)
print(f"Buy : {ans[0]} - Sell : {ans[1]}")
