#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive Approach
// ---------------------
// INTUITION - just from start check if the element if equal to it's next, if yes then resize the array and remove it and pass on the array 
// then increment the back index by 1 and make that number the current number else passon.
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N) Recursive call stack

void remove_duplicates_recursive( vector<int> &array, int index=0 ){
    if (index >= array.size()-1) return;
    if (array[index] == array[index+1]){
        array.erase(array.begin() + index + 1);
        remove_duplicates_recursive(array, index);
    }
    else remove_duplicates_recursive( array, index + 1);
}


// check
int main(){
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4 ,4, 9, 9};
    remove_duplicates_recursive(arr);
    for (auto num: arr) cout << num << " ";
    cout << endl;
    return 0;
}