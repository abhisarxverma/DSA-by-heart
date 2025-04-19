#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Brute Force Approach
---------------------
LOGIC - Take a new vector, loop the given vector and store the nonzero numbers in the vector and count the number of zeros, then fill the remaining places to the zeros.
TIME COMPLEXITY - O(2N) = O(N) - due to sorting
SPACE COMPLEXITY - O(N) - new vector
*/

vector<int> move_zeros_right_brute(vector<int> array){
    int n = array.size();
    if ( n <= 1 ) return array;
    vector<int> res;
    int zero_count = 0;
    for (auto num: array){
        if ( num != 0 ) res.push_back(num);
        else zero_count++;
    }
    for (int i = 0; i < zero_count; i++){
        res.push_back(0);
    }
    return res;
}

/*
Brute-2 Approach
---------------------
LOGIC - Using the bubble sort 
TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

vector<int> move_zeros_right_brute2( vector<int> array ){
    int n = array.size();
    if ( n <= 1 ) return array;

    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (array[j] == 0) swap(array[j], array[j+1]);
        }
    }
    return array;
}

/*
Better Approach
---------------------
LOGIC - Using the concept of quicksort, but the sequence will be changed
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> move_zeros_right_better( vector<int> array ){
    int n = array.size();
    if ( n <= 1 ) return array;
    int i = 0;
    int j = n-1;
    while (i < j){
        while (i < j && array[i] != 0) i++;
        while (i < j && array[j] == 0) j--;
        if ( i >= j ) break;
        swap(array[i], array[j]);
    }
    return array;
}

/*
Optimal Approach
---------------------
LOGIC - Two pointer approach, take two pointer and move the first pointer to the first zero, and then loop from the front of it to the end of array
if you find a non zero then as the j have the zero, swap them so that the zero will be replaced by the number, this will take all the zeros to right.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> move_zeros_right_optimal( vector<int> array ){
    int n = array.size();
    if ( n <= 1 ) return array;
    int j = -1;
    for (int i = 0; i < n ;i++){ // Take j to first zero
        if ( array[i] == 0 ){
            j = i;
            break;
        }
    }
    if ( j == -1 ) return array; // No zeros

    for (int i = j+1; i < n; i++){
        if ( array[i] != 0 ){
            swap(array[i], array[j++]);
        }
    }
    return array;
}


int main() {
    vector<int> vec = {1, 0, 2, 7, 0, 0, 5};
    vector<int> moved = move_zeros_right_optimal(vec);
    for (auto it: moved) cout << it << " ";
    cout << endl;
    return 0;
}