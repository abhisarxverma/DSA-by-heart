from typing import List
import heapq

'''
PROBLEM - Given an array of integers, which are the coordinates of the gas stations, Minimise the maximum distance between the coordinates by placing the given "k" number of integers.

EXAMPLE INPUT - [2, 8, 16, 25, 40], n = 4
EXAMPLE OUTPUT - 6
'''

'''
Brute Force Approach
---------------------
LOGIC - Linear search
Initialize tracking → Create how_many[] to store the number of additional gas stations in each gap.
Iteratively place k stations:
Find the largest gap between consecutive stations.
Insert a gas station in that gap, reducing its size.
Repeat for all k stations.
Calculate final max section length:
Recompute the biggest remaining section length after placing all stations.
Return this value as the minimum possible largest gap after placement.

TIME COMPLEXITY - O(N x K) 
SPACE COMPLEXITY - O(1)
'''

def gas_stations_brute( array: List[int], k: int ):
    n = len(array)
    how_many = [0] * (n-1)
    
    for gas_station in range(k):
        max_section = -1
        max_section_index = -1

        for i in range(n-1):
            diff = array[i+1] - array[i]
            section_length = diff // (how_many[i]+1)

            if section_length > max_section: 
                max_section = section_length
                max_section_index = i

        how_many[max_section_index] += 1

    max_section = -1
    for i in range(n-1):
        max_section = max(max_section, (array[i+1]-array[i])//(how_many[i]+1))

    return max_section

'''
Better Approach
---------------------
LOGIC - Binary search
Initialize a max heap (priority queue)
Store gaps between consecutive gas stations.
Always keep track of the largest gap.
Greedy station placement
Extract the largest gap from the heap.
Insert a gas station in this gap.
Recalculate the new gap and push it back into the heap.
Repeat for k stations
Continue splitting the largest gap iteratively, ensuring it reduces over time.
Final result
The top element of the heap gives the minimum possible largest gap after placing all stations.

TIME COMPLEXITY - O(K x LogN) 
SPACE COMPLEXITY - O(1)
'''

def gas_stations_better(array: List[int], k: int) -> float:
    n = len(array)
    how_many = [0] * (n - 1)
    q = []

    for i in range(n-1):  
        heapq.heappush(q, (-(array[i+1] - array[i]), -i))

    for gas_station in range(k):
        tp = heapq.heappop(q)
        section_index = -tp[1]  
        how_many[section_index] += 1

        initial_difference = -tp[0]  
        new_section_length = initial_difference / (how_many[section_index] + 1) 
        heapq.heappush(q, (-new_section_length, -section_index))

    return -heapq.heappop(q)[0]

'''
Optimal Approach
---------------------
LOGIC - Binary search
Define Search Space → low = 0 (smallest possible max gap)
high = max(arr[i+1] - arr[i]) (largest initial gap)
Binary Search on Maximum Gap (mid) → Try mid as a possible maximum distance
Calculate needed stations (get_number_of_gas_stations())
Adjust Search Based on Station Count → If more than k stations are required, increase low (current mid is too small).
Else, reduce high to get a smaller maximum gap.
Precision Condition (1e-6) → Stop when high - low is small enough, ensuring accuracy.
Final Result → high holds the minimum possible largest gap after placing k stations optimally.

TIME COMPLEXITY - O(N Log S) 
SPACE COMPLEXITY - O(1)
'''

def check_number_of_gas_stations( array: List[int], k: int, max_distance: int ) -> bool:
    n = len(array)
    count = 0

    for i in range(1, n):
        current_distance = array[i] - array[i-1]
        stations_in_between = current_distance // max_distance
        if stations_in_between == current_distance * max_distance: stations_in_between -= 1
        count += stations_in_between

    return count > k

def gas_stations_optimal( array: List[int], k: int ):
    n = len(array)
    low = 0
    high = 0

    for i in range(1, n):
        high = max(high, array[i] - array[i-1])

    diff = 1e-6
    while high-low > diff:
        mid = low + (high-low)/2.0
        if check_number_of_gas_stations(array, k, mid): low = mid
        else : high = mid

    return int(high)

array = [2, 8, 16, 25, 40]
stations = 4
print(f"Minimum maximum distance : {gas_stations_optimal(array, stations)}")