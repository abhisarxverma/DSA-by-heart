#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
PROBLEM - Given a matrix of integers, find the median of the array, if the matrix is sorted into one single array.
Also all the rows in the matrix are sorted.

EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

EXAMPLE OUTPUT - 
*/

/*
Brute Force Approach
---------------------
LOGIC - Flatten the matrix into one array, sort the array and return the median.
First loop over every row and then loop over every column in that row, add the number into a array.
Sort the array, then return the median number according to the size of the array.

TIME COMPLEXITY - O(NxM + Log(NxM)) 
SPACE COMPLEXITY - O(1)
*/

double matrix_median_brute(vector<vector<int>> matrix) {
    vector<int> flattened;

    for (auto row : matrix) {
        for (auto col : row) {
            flattened.push_back(col);
        }
    }

    sort(flattened.begin(), flattened.end());

    int s = flattened.size();
    if (s % 2 == 0) 
        return (flattened[s / 2] + flattened[s / 2 - 1]) / 2.0;  
    else 
        return flattened[s / 2];
}

/*
Optimal Approach
---------------------
LOGIC - 
Binary search on possible median values
We know the smallest and largest numbers in the matrix, so we search in that range.
Count numbers ≤ mid using upper_bound()
Since each row is sorted, we efficiently find how many elements are smaller or equal to mid.
Adjust search range
If the count is less than the required median position, we shift low up; otherwise, we decrease high.
Why? Instead of sorting the matrix, we leverage sorting within rows and binary search, reducing time complexity to O(N log max).

TIME COMPLEXITY - O(N Log(Max)) 
SPACE COMPLEXITY - O(1)
*/

int upper_bound(vector<int> array, int number) {
    int low = 0;
    int high = array.size();

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (array[mid] > number) 
            high = mid;
        else 
            low = mid + 1;
    }

    return low;
}

int count_small_equal(vector<vector<int>> matrix, int number) {
    int rows = matrix.size();  
    int count = 0;
    for (int i = 0; i < rows; i++) {  
        count += upper_bound(matrix[i], number);
    }
    return count;
}

int matrix_median_optimal(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);  
    }

    int required = (rows * cols) / 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int small_equal_count = count_small_equal(matrix, mid);
        
        if (small_equal_count < required) 
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return low;
}


int main() {
    vector<vector<int>> matrix = {
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}
    };
    int median = matrix_median_brute(matrix);
    cout << "Median : " << median << endl;
}