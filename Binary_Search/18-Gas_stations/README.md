# PROBLEM - Given an array of integers, which are the coordinates of the gas stations, Minimise the maximum distance between the coordinates by placing the given "k" number of integers.

### EXAMPLE INPUT - [2, 8, 16, 25, 40], n = 4
### EXAMPLE OUTPUT - 6

## ✅ Brute Force Approach

- **LOGIC** - *Linear search*
    - Initialize tracking → Create how_many[] to store the number of additional gas stations in each gap.
    - Iteratively place k stations:
    - Find the largest gap between consecutive stations.
    - Insert a gas station in that gap, reducing its size.
    - Repeat for all k stations.
    - Calculate final max section length:
    - Recompute the biggest remaining section length after placing all stations.
    - Return this value as the minimum possible largest gap after placement.

- **TIME COMPLEXITY** - ***O(N x K)***
- **SPACE COMPLEXITY** - ***O(N)***

## ✅ Better Approach

- **LOGIC** - *Priority Queue - keeps track of the minimum and maximum element*
    - Initialize a max heap (priority queue)
    - Store gaps between consecutive gas stations.
    - Always keep track of the largest gap.
    - Greedy station placement
    - Extract the largest gap from the heap.
    - Insert a gas station in this gap.
    - Recalculate the new gap and push it back into the heap.
    - Repeat for k stations
    - Continue splitting the largest gap iteratively, ensuring it reduces over time.
    - Final result
    - The top element of the heap gives the minimum possible largest gap after placing all stations.

- **TIME COMPLEXITY** - ***O(K x LogN)***
- **SPACE COMPLEXITY** - ***O(N)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search*
    - Define Search Space → `low = 0` (smallest possible max gap)
    - `high = max(arr[i+1] - arr[i])` (largest initial gap)
    - Binary Search on Maximum Gap `(mid)` → Try `mid` as a possible maximum distance
    - Calculate needed stations `(get_number_of_gas_stations())`
    - Adjust Search Based on Station Count → If more than k stations are required, increase low (current `mid` is too small).
    - Else, reduce `high` to get a smaller maximum gap.
    - Precision Condition `(1e-6)` → Stop when `high - low` is small enough, ensuring accuracy.
    - Final Result → `high` holds the minimum possible largest gap after placing `k` stations optimally.

- **TIME COMPLEXITY** - ***O(N Log S)***
- **SPACE COMPLEXITY** - ***O(1)***