#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
using namespace std;

// PROBLEM - Given an two sorted arrays, sort them without using any extra space inplace and return them.

/*
 EXAMPLE INPUT - {2, 9, 10} {5, 8, 15, 19}
 EXAMPLE OUTPUT - {2, 5, 8} {9, 10, 15, 19}
*/

/*
Brute Approach
---------------------
LOGIC - Use the Merge sort merging concept, and at last put the sorted array's elements back into the original two arrays.

TIME COMPLEXITY - O(N+M) merging
SPACE COMPLEXITY - O(N+M) merged sorted array
*/

void merge_without_extraspace_brute( vector<int> &array1, vector<int> &array2 ){
    int n = array1.size();
    int m = array2.size();
    int i = 0;
    int j = 0;
    vector<int> k;
    while ( i < n && j < m ){
        if ( array1[i] < array2[j] ){
            k.push_back(array1[i++]);
        }
        else {
            k.push_back(array2[j++]);
        }
    }
    while ( i < n ) k.push_back(array1[i++]);
    while ( j < m ) k.push_back(array2[j++]);

    // Put the merged sorted array back into the original arrays according to their lengths
    for (int i = 0; i < (n+m); i++){
        if ( i < n ) array1[i] = k[i];
        else array2[i-n] = k[i];
    }
}

/*
Better Approach
---------------------
LOGIC - 

Expand array1 to fit both arrays by adding zero placeholders.
Use three pointers (i, j, k):
i → Tracks last element in original array1
j → Tracks last element in array2
k → Tracks position in expanded array1
Merge in reverse order:
Compare elements at i and j, placing the larger one at k.
Reduce i or j accordingly.
Copy remaining elements from array2 if any are left.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(M)
*/

void merge_without_extraspace_better(vector<int> &array1, vector<int> &array2) {
    int n = array1.size();
    int m = array2.size();
    int i = n - 1, j = m - 1, k = n + m - 1;

    array1.resize(n + m, 0);  // Resize to accommodate all elements

    while (i >= 0 && j >= 0) {
        if (array1[i] > array2[j]) {
            array1[k] = array1[i];
            i--;
        } else {
            array1[k] = array2[j];  // Corrected assignment
            j--;
        }
        k--;
    }

    while (j >= 0) {
        array1[k] = array2[j];
        j--;
        k--;
    }

    array2 = std::vector<int>(array1.begin() + n, array1.end()); 
    array1 = std::vector<int>(array1.begin(), array1.begin() + n);
}

/*
Optimal Approach
---------------------
LOGIC - 
Start with a gap size (initially (n + m + 1) // 2), which helps in comparing elements far apart.
Compare and swap:
If both elements are in the first array (array1), swap if needed.
If one element is in array1 and the other in array2, swap if out of order.
If both are in array2, swap if needed.
Reduce the gap gradually and repeat until the entire array is merged properly.

TIME COMPLEXITY - O((n+m) log(n+m))
SPACE COMPLEXITY - O(1)
*/

void merge_without_extraspace_optimal(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int gap = (n + m + 1) / 2;  // Initial gap size

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < (n + m)) {
            // Case 1: Both elements in 'a'
            if (j < n && a[i] > a[j])
                swap(a[i], a[j]);
            // Case 2: One element in 'a', one in 'b'
            else if (i < n && j >= n && a[i] > b[j - n])
                swap(a[i], b[j - n]);
            // Case 3: Both elements in 'b'
            else if (i >= n && j >= n && b[i - n] > b[j - n])
                swap(b[i - n], b[j - n]);

            i++;
            j++;
        }

        // Reduce the gap using Shell Sort-like technique
        gap = (gap == 1) ? 0 : (gap + 1) / 2;
    }
}

int main() {
    vector<int> vec1 = {2, 9, 10};
    vector<int> vec2 = {5, 8, 15, 19};
    merge_without_extraspace_better(vec1, vec2);
    for ( auto num : vec1 ) cout << num << " ";
    cout << endl;
    for ( auto num : vec2 ) cout << num << " ";
    cout << endl;
}