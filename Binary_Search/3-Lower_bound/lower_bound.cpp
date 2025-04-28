#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
What is Lower Bound?

Lower bound is the type of binary search which returns the index of the number if it is int array,
and if the number is not in the array then it finds and give the next largest number in the array,
and if number itself is not present and no number is largest to the number it returns the size of the array which is not a valid index.

LOWER BOUND - IMPLEMENTATION
*/

/* ITERATIVE 1 */

int lower_bound( vector<int> array, int number ){
    int low = 0;
    int high = array.size()-1;
    int ans = array.size(); // To store the answer, and initialize this with array's size so that if no element is greater than number to find, then it will return the size

    while ( low <= high ){
        int mid = low + (high-low)/2;
        if ( array[mid] >= number ){
            ans = mid; // Store the current number, but we need to check more on left side cause if this is the number itself, this may not be the first occurence and if it is greater than the number, this may not be the next greater
            high = mid-1; // Try to find the answer in the left again
        } 
        else low = mid+1; // Answer is in the right half
    }

    return ans; // Return the answer
}

/* ITERATIVE 2 */   

int lower_bound_2( vector<int> array, int number ){
    int low = 0;
    int high = array.size();
    while ( low < high ){
        int mid = low + (high-low)/2;
        if (array[mid] >= number) high = mid; // This element can be the answer, cause either it is itself the number 
                                              // which we are finding, in this case we have to find the first occurence, and if the number is not in the array,
                                              // then this can be the next greater and that's why we have to keep it in the search space.
        else low = mid+1; // The answer is in the right half
    }

    return high; // The high will have the answer
}

/* RECURSIVE */

int lower_bound_recursive( vector<int> array, int number, int low, int high ){
    if ( low >= high ) return low;
    int mid = low + (high-low)/2;
    if ( array[mid] >= number ) return lower_bound_recursive(array, number, low, mid );
    else return lower_bound_recursive( array, number, mid+1, high );
}

int main() {
    vector<int> array = {1, 5, 9, 10, 32, 55};
    int ans = lower_bound_recursive(array, 100, 0, array.size());
    cout << "Ans : " << ans << endl;
}