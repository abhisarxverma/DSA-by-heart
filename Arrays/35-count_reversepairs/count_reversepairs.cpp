#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 PROBLEM - COUNT THE NUMBER OF THE REVERSE PAIRS WHICH ARE THE PAIRS IN WHICH THE LEFT ELEMENT IS MORE THAN TWICE OF THE RIGHT ELEMENT SIMILAR TO THE COUNT INVERSIONS

 EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}, n = 8
 EXAMPLE OUTPUT - 8
*/

/*
Brute Approach
---------------------
LOGIC - Loop over the array and then loop over the array on the right and increase the count
if you find any pair in which the first element is greater than the double the second element.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
*/

int count_reversepairs_brute(vector<int>& array) {
    int n = array.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > 2LL * array[j]) { // Use 2LL for safe multiplication
                count++;
            }
        }
    }
    return count;
}


/*
Optimal Approach
---------------------
LOGIC - MERGE SORT APPROACH - 
  1. Before merging, counting elements in the right half where `array[i] > 2 * array[j]` using a two-pointer technique.
  2. Merging the two halves while maintaining order.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
*/

int merge_with_counting(vector<int>& array, int low, int mid, int high) {
    int count = 0;

    // **Optimized Reverse Pair Counting Using Two Pointers**
    int j = mid + 1;
    for (int i = low; i <= mid; i++) { 
        while (j <= high && array[i] > 2LL * array[j]) { 
            j++;
        }
        count += j - (mid + 1);  
    }

    // Standard merge process
    vector<int> b;
    int i = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            b.push_back(array[i++]);
        } else {
            b.push_back(array[j++]);
        }
    }

    while (i <= mid) b.push_back(array[i++]);
    while (j <= high) b.push_back(array[j++]);

    for (int k = 0; k < b.size(); k++) {
        array[low + k] = b[k];  
    }

    return count;
}

int count_reversepairs_optimal(vector<int>& array, int low, int high) {
    if (low >= high) return 0;  // Base case

    int mid = (low + high) / 2;
    int leftCount = count_reversepairs_optimal(array, low, mid);
    int rightCount = count_reversepairs_optimal(array, mid + 1, high);
    int mergeCount = merge_with_counting(array, low, mid, high);

    return leftCount + rightCount + mergeCount;  // ✅ Accumulate total count
}


int main() {
    vector<int> vec = {8, 6, 1, 7, 5, 2, 3, 8};
    int reversepairs = count_reversepairs_optimal(vec, 0, vec.size()-1);
    cout << "Total reversepairs : " << reversepairs << endl;
}