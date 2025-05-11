#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
PROBLEM - Given a matrix, and a number to find, return the row and column number of that number
Every column and every row in matrix internally sorted, but the matrix as a whole is not sorted.

EXAMPLE INPUT - 
        {1, 5, 10, 15},
        {19, 23, 32, 36},
        {32, 38, 39, 48},
        {42, 45, 46, 50}

        Number = 39

EXAMPLE OUTPUT - (2, 2)
*/

/*
Brute Force Approach
---------------------
LOGIC - Double nested loops
Loop over every row and then loop over every column
return the row and column number if found, else return (-1, -1)

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
*/

pair <int, int> coords_in_matrix_brute( vector<vector<int>> matrix, int number ){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int row = 0; row < rows; row++){
        for ( int col = 0; col < cols; col++){
            if (matrix[row][col] == number) return {row, col};
        }
    }
    return {-1, -1};
}

/*
Better Approach
---------------------
LOGIC - Loop over the rows, and because the row is sorted we can check that the number we are finding is in that range or not
If the number is in that range then do the binary search and find the number, also note there can be multiple rows with the range that can have the number
That's why we need to check every row with the range we need
return the row and column number if number found, else return (-1, -1)

TIME COMPLEXITY - O(N x LogM) 
SPACE COMPLEXITY - O(1)
*/

pair<int, int> coords_in_matrix_better( vector<vector<int>> matrix, int number ){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int row = 0; row < rows; row++){
        int low = 0;
        int high = cols-1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (matrix[row][mid] == number) return {row, mid};
            if (matrix[row][mid] > number) high = mid-1;
            else low = mid+1;
        }
    }
    return {-1, -1};
}
/*
Optimal Approach
---------------------
LOGIC - We will have two variables i and j
We know that the rows and columns on itself is sorted we will take advantage of that
i will be at the top row which is 0 index of matrix
j will be at the last column of top row which is total columns-1 index
And do a while loop till the i pointer becomes equal to the total rows-1 and j pointer becomes -1
Means we will start form the top right corner of the matrix
in the loop we will check if the number at the point is the number we are finding if yes return that row and column index
And if the number at that point is greater than the number we are finding, then this means that all the numbers in that column further are greater
Hence we will discard that column completely and search in one column before
But also if the number at that point is smaller than the number we are finding then this means that all the numbers in that row before are smaller 
Hence we will discard that row completely and search in the next row 
We will repeat this process and eventually if number is present we will get that.

TIME COMPLEXITY - O(N + M) 
SPACE COMPLEXITY - O(1)
*/

pair<int, int> coords_in_matrix_optimal( vector<vector<int>> matrix, int number ){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int i = 0;
    int j = cols-1;

    while ( i < rows && j >= 0 ){
        if (matrix[i][j] == number) return {i, j};
        else if (matrix[i][j] > number) j--;
        else i++;
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 10, 15},
        {19, 23, 32, 36},
        {32, 38, 39, 48},
        {42, 45, 46, 50}
    };
    int number_to_find = 22;
    pair<int, int> ans = coords_in_matrix_brute(matrix, number_to_find);
    if ( ans.first == -1 ){
        cout << number_to_find << " is not in the matrix." << endl;
    }
    else {
        cout << number_to_find << " is at row : " << ans.first << " and at column : " << ans.second << endl;
    }
}