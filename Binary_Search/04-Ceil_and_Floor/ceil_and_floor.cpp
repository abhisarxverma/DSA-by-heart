#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* CEIL IMPLEMENTATION USING BINARY SEARCH */

/* What is Ceil?

Ceil is the function that on giving the array and the number of which ceil is to be found
returns the number if it itself is present and if not then returns the next greater number in array
and if the no number is greater in the array then it returns the size of the array

[ SAME AS LOWER BOUND ]
*/

int ceil( vector<int> array, int number ){

    // Implement the lower bound
    int low = 0;
    int high = array.size();
    while ( low < high ){
        int mid = low + (high-low)/2;
        if ( array[mid] >= number ) high = mid;
        else low = mid+1;
    }

    return (low == array.size()) ? -1 : array[low];
}

/* FLOOR IMPLEMENTATION USING BINARY SEARCH */

/* What is Floor?

Foor is the function that on giving the array and the number of which the floor is to be found
returns the number itself if it is present, and if the number is not present, then returns the 
next shorter number in the array and if no number is shorter then returns the -1
*/

int floor( vector<int> array, int number ){
    int low = 0;
    int high = array.size()-1;
    int ans = -1;

    while ( low <= high ){
        int mid = low + (high - low)/2;
        if ( array[mid] > number ){
            high = mid-1;
        }
        else if ( array[mid] <= number ) {
            ans = array[mid];
            low = mid+1;
        }
    }

    return ans;
}

int main() {
    vector<int> array = {1, 5, 6, 10, 50, 100};
    int ans = floor(array, 55);
    cout << "Ans : " << ans << endl;
}