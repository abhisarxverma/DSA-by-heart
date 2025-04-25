#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 PROBLEM - Count the total number of the pairs that can be formed in which the first element is greater than the second one.

 EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}
 EXAMPLE OUTPUT - 15

*/

/*
Brute Approach
---------------------
LOGIC - Loop over the array and then loop over the right of the array and increase the count if 
you find a pair in which the second element is smaller than the frist one.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
*/

int count_inveresion_brute( vector<int> array ){
    int n = array.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if ( array[i] > array[j] ) count++;
        }
    }
    return count;
}

/*
Optimal Approach
---------------------
LOGIC - MERGE SORT APPROACH - Using the MERGESORT concept of merging the sorted arrays. while merging we will get the count by compairing the elements with the trick

TIME COMPLEXITY - O(N LogN) Merge sort time complexity
SPACE COMPLEXITY - O(N) for merging
*/

int getCountWithMerging(vector<int>& a, int low, int mid, int high) {
    int res = 0;
    int i = low, j = mid + 1;
    vector<int> b;  // Temporary merged vector

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b.push_back(a[i]);
            i++;
        } else {  // Inversion found
            b.push_back(a[j]);
            j++;
            res += (mid - i + 1);  // Count inversions
        }
    }

    while (i <= mid) b.push_back(a[i++]);
    while (j <= high) b.push_back(a[j++]);

    // Copy back merged result into original array
    for (int k = 0; k < b.size(); k++) {
        a[low + k] = b[k];
    }

    return res;
}

int count_inversions_optimal(vector<int>& a, int low, int high) {
    if (low >= high) return 0;  // Base case

    int mid = (low + high) / 2;
    int leftCount = count_inversions_optimal(a, low, mid);
    int rightCount = count_inversions_optimal(a, mid + 1, high);
    int mergeCount = getCountWithMerging(a, low, mid, high);

    return leftCount + rightCount + mergeCount;  // Accumulate total inversion count
}

int main() {
    vector<int> vec = {8, 6, 1, 7, 5, 2, 3, 8};
    int inversions = count_inversions_optimal(vec, 0, vec.size()-1);
    cout << "Inversions : " << inversions  << endl;
}