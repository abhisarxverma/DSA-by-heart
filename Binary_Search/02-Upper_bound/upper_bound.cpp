#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
What is Upper Bound?

Upper bound is the type of binary search which returns always the next largest number in the array even if the number itself is present,
and if there is no number in the array that is larger than the number to find, then it returns the size of the array, or you can say last element.

UPPER BOUND - IMPLEMENTATION
*/

/* ITERATIVE 1 */

int upper_bound( vector<int> array, int number ){
    int low = 0;
    int high = array.size()-1;
    int ans = array.size(); // To store the answer, and initialize this with array's size so that if no element is greater than number to find, then it will return the size

    while ( low <= high ){
        int mid = low + (high-low)/2;
        if ( array[mid] <= number ) low = mid+1; // Answer is in the right half
        else {
            ans = array[mid]; // Store the current element which maybe the answer, we are not sure cause even if this is greater than number to find, this may be not the next largest, so need to find the next largest in the left half
            high = mid-1;     // Go and find more close largest in left half
        }
    }

    return ans; // Return the answer
}

/* ITERATIVE 2 */   

int upper_bound_2( vector<int> array, int number ){
    int low = 0;
    int high = array.size();
    while ( low < high ){
        int mid = low + (high-low)/2;
        if (array[mid] <= number) low = mid+1; // The answer is in the right half
        else high = mid; // This is a conceptual shortcut, that if this is greater than the number to find, this maybe the answer. So unlike in traditional in which 
                         // we discard the mid element along with the right, here we will discard the right and take the mid element in the search space, cause this maybe the answer.
    }

    return high; // The high will have the answer
}

/* RECURSIVE */

int upper_bound_recursive( vector<int> array, int number, int low, int high ){
    if ( low >= high ) return low;
    int mid = low + (high-low)/2;
    if (array[mid] <= number) return upper_bound_recursive(array, number, mid+1, high);
    else return upper_bound_recursive(array, number, low, mid);
}

int main() {
    vector<int> array = {1, 5, 9, 10, 32, 55};
    int ans = upper_bound_2(array, 6);
    cout << "Ans : " << ans << endl;
}