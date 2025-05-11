#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
PROBLEM - Given a matrix, in which every 2 elements are different, and the rows and columns are not sorted,
Also, you can assume that the border of the matrix is -1. This means that you can assume that the number next or before to the numbers at end are -1.
Find the greatest Peak element and return that.

EXAMPLE INPUT - 
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}

EXAMPLE OUTPUT - 50
*/

/*
Brute Force Approach
---------------------
LOGIC - Double nested Looping over rows and columns
Loop over rows and then loop over the columns
if you find a number which is greater than both of its side number in that row
then return the number

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
*/

int peak_element_2d_matrix_brute( vector<vector<int>> matrix ){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int peak_element = -1;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            if ( (col == 0 || matrix[row][col] > matrix[row][col-1]) 
            && (col == cols-1 || matrix[row][col] > matrix[row][col+1]) ) {
                peak_element = matrix[row][col];
            }
        }
    }
    return peak_element;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search peak element method
The logic here is based in the normal peak element algorithm of binary search
In the normal prodecure we tried to go to the right if the mid is in the ascending portion
And we tried to go to the left if the mid is in the descending portion.
Why? cause if there is no peak element in array, if the array is ascending the last number will always be the peak element
and if the array is descending the first number will always be the peak element and we try to go that direction.
But, here one condition added to this normal peak element search is that the peak element must also be greater than the upper and lower numbers
So we will have a helper function that will give us the index of the largest number in any column given
While doing the binary search on the columns we will pass the mid to the function and get the index of the largest number
Taking the largest number in column already solves the half the problem.
Now we will do the same peak element search thing, we will go right or left according to the ascending or descending.
This will give us the peak element, cause alreay we are first going to the number in column that is greater than both of it's upper and lower number
and we are trying to just find from all the maximums from all the columns the number which is also greater than the left and right numbers.

TIME COMPLEXITY - O(N x LogM) 
SPACE COMPLEXITY - O(1)
*/

int column_max_index( vector<vector<int>> matrix, int col ){
    int rows = matrix.size();
    int max_number = INT_MIN;
    int max_index = -1;

    for (int row = 0; row < rows; row++){
        if (matrix[row][col] > max_number){
            max_number = matrix[row][col];
            max_index = row;
        }
    }
    return max_index;
}

int peak_element_2d_matrix_optimal( vector<vector<int>> matrix ){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0;
    int high = cols-1;

    while (low <= high){
        int mid = low + (high-low)/2;
        int max_index = column_max_index(matrix, mid);
        int element = matrix[max_index][mid];
        int left = (max_index-1 >= 0) ? matrix[max_index-1][mid] : -1;
        int right = (max_index+1 < cols) ? matrix[max_index+1][mid] : -1;
        if (element > left && element > right) return element;
        else if ( left > element ) high = mid-1;
        else if ( right > element ) low = mid+1;
    }

    return -1;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 4, 5},
        {19, 23, 32, 36},
        {48, 50, 38, 32},
        {42, 45, 46, 50}
    };
    vector<vector<int>> matrix2 = {
        {1},
        {4},
        {2},
        {5},
        {3}
    };
    int peak_element = peak_element_2d_matrix_optimal(matrix);
    cout << "Peak element : " << peak_element << endl;
}