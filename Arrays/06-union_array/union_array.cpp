#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
Brute Force Approach
---------------------
LOGIC - Take a set, put all the numbers from both the input vectors into the new set, the set will do both the sorting and removing duplicates, then 
convert the set back to vector and return it.

TIME COMPLEXITY - O(2(N+M) x Log(N+M)) for sorting of res array
SPACE COMPLEXITY - O(N+M) res array
*/

vector<int> union_array_brute( vector<int> arr1, vector<int> arr2 ){
    int n = arr1.size();
    int m = arr2.size();
    if (n + m == 0) return arr1;
    else if ( n == 0 ) return arr2;
    else if ( m == 0 ) return arr1;
    set<int> s; // set will store uniques and also sort the numbers

    for (int i = 0; i < n+m; i++){ // N+M x Log(N+M) for set insertion
        if (i < n) s.insert(arr1[i]);
        else s.insert(arr2[i-n]);
    }
    vector<int> res(s.begin(), s.end()); // N+M set to vector
    return res;
}

/*
Optimal Approach
---------------------
LOGIC - Using the merge sort concept of merging two sorted arrays
TIME COMPLEXITY - O(N+M Log N+M) 
SPACE COMPLEXITY - O(N+M)
*/

vector<int> union_array_optimal( vector<int> arr1, vector<int> arr2 ){
    int n = arr1.size();
    int m = arr2.size();
    if (n + m == 0) return arr1;
    
    int i = 0;
    int j = 0;
    vector<int> res;
    while ( i < n && j < m ){
        if ( arr1[i] < arr2[j] ){
            res.push_back(arr1[i]);
            i++;
        }
        else if ( arr2[j] < arr1[i] ){
            res.push_back(arr2[j]);
            j++;
        }
        else {
            res.push_back(arr1[i]);
            i++; j++;
        }
    }
    while ( i < n ){
        res.push_back(arr1[i]);
        i++;
    }
    while ( j < m ){
        res.push_back(arr2[j]);
        j++;
    }
    return res;
}

int main() {
    vector<int> a1 = {1, 4, 7, 9};
    vector<int> a2 = {0, 7, 9};
    vector<int> merged = union_array_optimal(a1, a2);
    for (auto it: merged) cout << it << " ";
    cout << endl;
    return 0;
}