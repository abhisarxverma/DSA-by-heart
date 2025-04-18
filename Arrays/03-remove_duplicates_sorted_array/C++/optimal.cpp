#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
Optimal Approach
---------------------
Logic: Take a pointer back and initialize it to zero, loop from 1st index to end and if the number at that index is not equal to number at back index.
then make the number next to the back index that number and increment the back and at last resize the array to back + 1 cause the till back index all the 
number will be unique.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)

*/

vector<int> remove_duplicates_optimal(vector<int> &array) {
    if (array.empty() || array.size() == 1) return array;
    
    int back = 0;
    
    for (int front = 1; front < array.size(); front++) {
        if (array[front] != array[back]) {
            back++;
            array[back] = array[front]; 
        }
    }
    array.resize(back + 1);
    return array;
}


int main() {    
    vector<int> vec = {1, 1, 2, 3, 5, 5, 7, 7, 7, 9, 9};
    // CHECK
    vector<int> res = remove_duplicates_optimal(vec);
    for (auto num: res){
        cout << num << " ";
    }cout << endl;
    return 0;
}
