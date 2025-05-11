#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
PROBLEM - Given a full sorted matrix, means the whole matrix as one array, is sorted and you have to find the given number in the matrix.

INPUT - {1, 5, 10, 15},
        {19, 23, 27, 30},
        {32, 35, 39, 40},
        {42, 45, 46, 50}

        Number = 39

OUTPUT - True
*/

/*
Brute Force Approach
---------------------
LOGIC - Double nested looping

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
*/

bool find_in_sorted_matrix_brute( vector<vector<int>> matrix, int number ){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (auto row : matrix){
        for ( auto col : row){
            if ( col == number ) return true;
        }
    }
    return false;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
Cause the whole matrix is sorted we can do normal binary seach
We will take mid but also we will do modulos to the rows and cols
So that the mid gets to the right row and the column

TIME COMPLEXITY - O(Log (NxM)) 
SPACE COMPLEXITY - O(1)
*/

bool find_in_sorted_matrix_optimal( vector<vector<int>> matrix, int number ){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0;
    int high = (rows * cols)-1;

    while (low <= high){
        int mid = low + (high-low)/2;
        mid = mid % rows;
        int row = mid % rows;
        int col = mid % cols;
        if (matrix[row][col] == number) return true;
        else if ( matrix[row][col] > number ) high = mid-1;
        else low = mid+1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 10, 15},
        {19, 23, 27, 30},
        {32, 35, 39, 40},
        {42, 45, 46, 50}
    };
    int number_to_find = 99;
    if (find_in_sorted_matrix_optimal(matrix, number_to_find)) cout << number_to_find << "is present in matrix." << endl;
    else cout << number_to_find << " is not present in matrix." << endl;
    cout << "Thank you !" << endl;
}