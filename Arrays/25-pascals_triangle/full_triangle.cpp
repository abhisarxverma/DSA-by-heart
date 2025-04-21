#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PROBLEM - Given the row number give the full pascal's triangle up to that row

// EXAMPLE INPUT - 4
// EXAMPLE OUTPUT 
/*
           1 
          1 1 
         1 2 1 
        1 3 3 1 
*/

/*
Brute Approach
---------------------
LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(N^2) to return the triangle
*/

int nCr_optimal(int n, int r) {
    long long res = 1;
    if (r > n - r) r = n - r; // Optimize by using the smaller r
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

vector<vector<int>> create_pascals_triangle_brute( int n ){
    vector<vector<int>> res;
    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j <= i; j++){
            row.push_back(nCr_optimal(i, j));
        }
        res.push_back(row);
    }
    return res;
}
/*
Optimal Approach
---------------------
LOGIC - Loop for the n times which is the number of rows, and for each of that iteration, create the 
row using the optimal approach to create the row in the O(n) times.

TIME COMPLEXITY - O(N^2) same as brute but less redundant operations
SPACE COMPLEXITY - O(N^2) to return the triangle
*/

vector<int> row_in_pascals_triangle_optimal(int row) {
    vector<int> res = {1};  // Start with 1
    
    for (int i = 1; i < row; i++) {
        res.push_back(res.back() * (row - i) / i);
    }
    
    return res;
}

vector<vector<int>> create_pascals_triangle_optimal( int n ){
    vector<vector<int>> res;
    for ( int i = 0; i < n; i++){
        res.push_back(row_in_pascals_triangle_optimal(i+1));
    }
    return res;
}

int main() {
    vector<vector<int>> triangle = create_pascals_triangle_optimal(10);
    for (auto row: triangle){
        for (auto num: row){
            cout << num << " ";
        }
        cout << endl;
    }
}