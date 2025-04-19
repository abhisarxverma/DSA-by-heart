#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
Brute Force Approach
---------------------
LOGIC - Loop over the any one vector, the nestedly loop over other vector, and if you find any number same as the outer number 
then add it to the result vector, and it will automatically be in sorted order, so no need to sort.
straight return the result vector.

TIME COMPLEXITY - O((N+M)^2)
SPACE COMPLEXITY - O(N+M) result array to return
*/

vector<int> intersection_array_brute( vector<int> arr1, vector<int> arr2 ){
    int n = arr1.size();
    int m = arr2.size();
    if (n+m == 0) return arr1;

    vector<int> res;
    for (auto i : arr1){
        for (auto j : arr2){
            if (j == i){
                res.push_back(j);
            }
        }
    }
    return res;
}

/*
Optimal Approach
---------------------
LOGIC - Using the merge sort concept of merging two sorted arrays
TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(N+M)
*/

vector<int> intersection_array_optimal( vector<int> arr1, vector<int> arr2 ){
    int n = arr1.size();
    int m = arr2.size();
    if ( n+m == 0 ) return arr1;

    int i = 0, j = 0;
    vector<int> res;
    while ( i < n && j < m ){
        if ( arr1[i] < arr2[j] ){
            i++;
        }
        else if ( arr2[j] < arr1[i] ){
            j++;
        }
        else {
            res.push_back(arr1[i]);
            i++; j++;
        }
    }
    return res;
}

int main() {
    vector<int> a1 = {1, 4, 7, 9};
    vector<int> a2 = {0, 7, 9};
    vector<int> merged = intersection_array_optimal(a1, a2);
    for (auto it: merged) cout << it << " ";
    cout << endl;
    return 0;
}