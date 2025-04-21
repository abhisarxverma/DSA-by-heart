#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

// PROBLEM - Rotate the given square matrix in a clockwise direction

/* EXAMPLE INPUT MATRIX   EXAMPLE OUTPUT MATRIX
         1, 2, 3, 4          13 9 5 1 
         5, 6, 7, 8          14 10 6 2 
         9, 10, 11, 12       15 11 7 3 
         13, 14, 15, 16      16 12 8 4

*/
// helper function to print matrix after rotating to check
void print_matrix(vector<vector<int>> &m){
    for (auto row : m){
        for (auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }
}

/*
Brute Approach
---------------------
LOGIC - Loop over the rows, then loop over the columsn in reverse order, take a new result vector, place
the numbers at their new indexes according to the relation between the indexes - 

matrix[row][col] -> new_matrix[col][row]

TIME COMPLEXITY - O(n^2)
SPACE COMPLEXITY - O(n^2)
*/

vector<vector<int>> rotate_90_degrees_brute( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> res(n, vector<int>(n, 0));  // ✅ Creates an n x n matrix

    for (int j = 0; j < n; j++){
        for (int i = n-1; i >= 0 ; i--){
            res[j][(n-1)-i] = matrix[i][j];
        }
    }
    return res;
}

/*
optimal Approach
---------------------
LOGIC - Transpose the matrix , and then reverse every row

TIME COMPLEXITY - O(n^2) nearly
Transpose - O(n/2 * n/2) nearly
Reverse - O(n * n/2);

SPACE COMPLEXITY - O(1)
*/

vector<vector<int>> transpose_matrix( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n ; i++){
        for (int j = i+1; j < m; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    return matrix;
}

vector<vector<int>> rotate_90_degrees_optimal( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();

    matrix = transpose_matrix(matrix);
    for (int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
    };
    vector<vector<int>> rotated = rotate_90_degrees_optimal(matrix);
    print_matrix(rotated);
}