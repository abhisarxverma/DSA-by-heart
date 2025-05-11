#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
PROBLEM - Given a 2d matrix of 0s and 1s, in which the rows are sorted, find the row number with the maximum 1s, in case of the multiples return the minimum index.

INPUT - {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1}

OUTPUT - 1
*/

/*
Brute Force Approach
---------------------
LOGIC - Take a highest variable and a current count variable
Loop over every row, then loop over every column
We will take little advantage of the sorted feature of the rows in matrix
As soon as we find the first one in the column, we will add the total count of ones in that row
Total count will be Total columns - This column index to the current count
update the highest if the current_count is greater than the highest
return the highest

TIME COMPLEXITY - O(N x M) 
SPACE COMPLEXITY - O(1)
*/

int maximum_ones_brute( vector<vector<int>> matrix ){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int highest = -1;
    int highest_count = 0;

    for ( int row = 0; row < rows; row++){
        int current_count = 0;
        for ( int col = 0; col < cols; col++){
            if ( matrix[row][col] == 1 ) {
                current_count += cols-col;
                break;
            }
        }
        if ( current_count > highest_count ) {
            highest_count = current_count;
            highest = row;
        }
    }

    return highest;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
We will loop over every row
And as the rows are sorted
We will find the first occurence of the "1" using Binary search
If 1 found then it's count will be total columns - first occurence index
If the count is greater than the highest count then update the highest count and the highest index which we have to return.

TIME COMPLEXITY - O(N x Log(M)) 
SPACE COMPLEXITY - O(1)
*/

int maximum_ones_optimal( vector<vector<int>> matrix ){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int highest = -1;
    int highest_count = 0;

    for (int row = 0; row < rows; row++){
        int low = 0;
        int high = cols;

        while ( low < high ){
            int mid = low + (high-low)/2;
            if ( matrix[row][mid] == 1 ) high = mid;
            else low = mid+1;
        }

        if (low != cols && matrix[row][low] == 1){
            int current_count = cols-low;
            if ( current_count > highest_count ){
                highest_count = current_count;
                highest = row;
            }
        }
    }

    return highest;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };
    cout << "Maximum ones row index : " << maximum_ones_optimal(matrix) << endl;
}