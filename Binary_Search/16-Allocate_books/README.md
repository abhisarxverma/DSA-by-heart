# PROBLEM - Given an array of books, distribute the books to "m" students such that the maximum allocated books to any student is minimum.

### EXAMPLE INPUT - [10, 20, 30, 40], n = 2
### EXAMPLE OUTPUT - 60

## ✅ Brute Force Approach

- **LOGIC** - *Linear search*
    - We have to find the minimum of maximum books that a student get so we will loop linearly from low to highest answer possible
    - We will take low as the maximum books in array, cause the by starting from the maximum we can distribute all the books in array
    - We will take high as the sum of books in array, cause the we can only distribute as much books we have in array
    - While looping we will check if with that books distribution maximum we are able to distribute to the target number of students
    - As we are looping from low to high, the first time we will find answer we will retutn that.

- **TIME COMPLEXITY** - ***O(N x (sum-max(array)))***
- **SPACE COMPLEXITY** - ***O(1)***

## ✅ Optimal Approach

- **LOGIC** - *Binary search*
    - We set the range for binary search based on possible values for book allocation:
    - `low = max(books)` → The least possible maximum load (A student must get at least one book, so the largest book size is the minimum allocation).
    - `high = sum(books)` → The worst case, where a single student gets all the books.
    - We perform binary search on this range:
    - Pick `mid = (low + high) / 2` as the potential maximum allocation.
    - Check if we can assign books to students within this limit.
    - If it's possible → Try to reduce allocation `(high = mid - 1)`.
    - If it's not possible → Increase allocation `(low = mid + 1)`.
    - Once binary search completes, low holds the minimum possible maximum allocation for students.

- **TIME COMPLEXITY** - ***O(N * Log(sum-max(array)))*** 
- **SPACE COMPLEXITY** - ***O(1)***