#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// PROBLEM - Given the row number give the sequence of the numbers in that row in the pascal's triangle

// EXAMPLE INPUT - 4
// EXAMPLE OUTPUT - 1 3 3 1

/*
Brute Approach
---------------------
LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

TIME COMPLEXITY - O(Nxr)
SPACE COMPLEXITY - O(1)
*/

int nCr(int n, int r) {
    long long res = 1;
    if (r > n - r) r = n - r; 
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

vector<int> row_in_pascals_triangle_brute( int row ){
    vector<int> res;
    long long number = 1;

    for (int i = 0; i < row; i++){
        res.push_back(nCr(row-1, i));
    }
    return res;
}

/*
Optimal Approach
---------------------
LOGIC - Loop for the n times which is the number of rows and for every iteration, calculate the 
number at that position using the ncr and add it to the result vector.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> row_in_pascals_triangle_optimal(int row) {
    vector<int> res = {1};  // Start with 1
    
    for (int i = 1; i < row; i++) {
        res.push_back(res.back() * (row - i) / i);
    }
    
    return res;
}

int main() {
    vector<int> row = row_in_pascals_triangle_brute(5);
    for (auto num: row) cout << num << " ";
    cout << endl;
    return 0;
}