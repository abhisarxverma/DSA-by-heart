#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PROBLEM - Given a matrix, print the elements of the matrix in spiral order.

/*
Optimal Approach
---------------------
LOGIC - Take 4 variables to keep track of the rows and columns to print and got printed, and move in 
spiral order while updating the variables.

TIME COMPLEXITY - O(NxM)
SPACE COMPLEXITY - O(1)
*/

void print_spiral_matrix(vector<vector<int>> matrix) {
    int n = matrix.size();
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
            cout << matrix[top][i] << " ";
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;

        // Traverse from right to left (if valid)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }

        // Traverse from bottom to top (if valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";  // Fixed index
            left++;
        }
    }
}


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    print_spiral_matrix(matrix);
    return 0;
}