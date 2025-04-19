#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// Sort the array containing only zeros, ones and twos

/*
Brute Force Approach
---------------------
LOGIC - Use any sorting method like bubble sort O(n^2), merge sort (n log n), quick sort (n^2), selection sort(n^2), insertion sort(n^2)
I have used the selection sort.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

vector<int> sort_zeros_ones_twos_brute( vector<int> &array ){
    // Selection sort - select the minimum and place it at it's place
    int n = array.size();
    for (int i = 0; i < n-1; i++ ){
        int temp = i;
        for (int j = i+1; j < n; j++){
            if ( array[j] < array[temp]) temp = j;
        }
        swap(array[i], array[temp]);
    }
    return array;
}

/*
Better Approach
---------------------
LOGIC - Count the number of zeros, ones and twos and place them one by one

TIME COMPLEXITY - O(2N) = O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> sort_zeros_ones_twos_better( vector<int> array ){
    int n = array.size();
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;

    for (auto n: array){
        if ( n == 0 ) zero_count++;
        else if ( n == 1 ) one_count++;
        else two_count++;
    }

    vector<int> result;
    for (int i = 0; i < n; i++){
        if (zero_count) {
            result.push_back(0);
            zero_count--;
        }
        else if (one_count) {
            result.push_back(1);
            one_count--;
        }
        else {
            result.push_back(2);
            two_count--;
        }
    }
    return result;
}

/*
Optimal Approach
---------------------
LOGIC - Dutch National Flag Algorithm - Take two pointers, send the zeros to the left of first, ones 
to middle, and the twos to the right of second pointer.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> sort_zeros_ones_twos_optimal( vector<int> array ){
    int n = array.size();
    if (n <= 1) return array;

    int low = 0;
    int high = n-1;
    int current = 1;
    while (current < high){
        if (array[current] == 0){
            swap(array[low], array[current]);
            low++; current++;
        }
        else if (array[current] == 1) current++;
        else {
            swap(array[current], array[high]);
            high--; 
        }
    }
    return array;
}

int main() {
    vector<int> vec = {1, 0, 2, 0, 1, 1, 2, 0};
    vector<int> sorted = sort_zeros_ones_twos_optimal(vec);
    for (auto it: sorted) cout << it << " ";
    cout << endl;
    return 0;
}