#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

// PROBLEM - Set matrix zeros

/* EXAMPLE INPUT MATRIX   EXAMPLE OUTPUT MATRIX
    1, 1, 1, 1, 1             0, 0, 1, 0, 0
    0, 1, 1, 0, 1             0, 0, 0, 0, 0
    1, 1, 1, 1, 0             0, 0, 1, 0, 0
    1, 0, 1, 1, 1             0, 0, 0, 0, 0
    1, 1, 1, 1, 1             0, 0, 1, 0, 0
*/

/*
Brute Approach
---------------------
LOGIC - Loop over rows, then loop over columns and if you find any zero, then loop over it's row and column and
mark all the numbers -1, we cannot mark them zero directly because if we do that then for the futher places, we
may uneccecarily mark the ones zeros, which will be wrong.

TIME COMPLEXITY - O(NxM x N+M)
SPACE COMPLEXITY - O(1)
*/

vector<vector<int>> set_matrix_zeros_brute( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 0){
                for (int x = 0; x < m ;x++) {
                    matrix[i][x] = -1;
                }
                for (int x = 0; x < n ;x++) {
                    matrix[x][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            if (matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
    return matrix;
}

/*
Better Approach
---------------------
LOGIC - Use a two vectors, row and cols, to save which cols and which rows to be turned zero, then at last
turn all that row and col into zero.

TIME COMPLEXITY - O(2 NxM)
SPACE COMPLEXITY - O(N+M)
*/

vector<vector<int>> set_matrix_zeros_better( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> zero_rows(n);
    vector<int> zero_cols(m);

    // loop the matrix and store the 0 rows and cols
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            if (matrix[i][j] == 0){
                zero_rows[i] = 1;
                zero_cols[j] = 1;
            }
        }
    }

    // change the zero rows and cols to zero
    for (int i = 0; i < n ;i++){
        for (int j = 0; j < m; j++){
            if (zero_rows[i] == 1 || zero_cols[j] == 1) matrix[i][j] = 0;
        }
    }

    return matrix;
}

/*
Optimal Approach
---------------------
LOGIC - store which rows and which columsn to be made zeros in the first row and the first column itself,
then by checking the first row and first column, make the rest of the matrix 0, and at last, first check if the
first column of the first row is zero, if yes then make the first row zero, and then check if the first col to be 
made zero which we have in the col0 variable, if yes then make the first col 0.

TIME COMPLEXITY - O(2 NxM) = O(NxM)
SPACE COMPLEXITY - O(1)
*/

vector<vector<int>> set_matrix_zeros_optimal( vector<vector<int>> &matrix ){
    int n = matrix.size();
    int m = matrix[0].size();

    int col0 = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;
                if ( j == 0 ) col0 = 0;
                else matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if ( matrix[0][j] == 0 || matrix[i][0] == 0 ) matrix[i][j] == 0;
        }
    }
    if ( matrix[0][0] == 0 ){
        for (int i = 0; i < m; i++) matrix[0][i] = 0;
    }
    if (!col0) {
        for (int i = 0; i < n; i++) matrix[i][0] = 0;
    }
    return matrix;
}

int main() {
    vector<vector<int>> vec = {
        { 1, 1, 1, 1, 1 },
        { 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
    vector<vector<int>> res = set_matrix_zeros_better(vec);
    for (auto row : res){
        for ( auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}