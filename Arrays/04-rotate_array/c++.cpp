#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Brute Force Approach
---------------------
LOGIC - Take a temporary array, put all the numbers to before the rotation point that is before the times of rotation
shif the original array and then put the number from the temporary array to the left or right based on the direction of rotation
TIME COMPLEXITY - O(2N)
SPACE COMPLEXITY - O(times) temp array
*/

vector<int> left_rotation_brute(vector<int> array, int times){
    if (array.size() <= 1)  return array;
    times = times % array.size();
    if (times == 0) return array;
    vector<int> temp(times);
    for (int i = 0; i < times; i++) temp[i] = array[i]; // Store numbers before the rotation point in temp
    for (int i = times; i < array.size(); i++) array[i-times] = array[i]; // Shift numbers from the index times to end to the start
    for (int i = 0; i < temp.size(); i++) array[array.size()-times+i] = temp[i]; // put the number in temp at the last
    return array;
}

vector<int> right_rotation_brute(vector<int> array, int times){
    if (array.size() <= 1) return array;
    times = times % array.size();
    if (times == 0) return array;
    vector<int> temp(times);
    for (int i = 0; i < times; i++) temp[i] = array[array.size()-times+i];
    for (int i = array.size()-times-1; i >= 0; i--) array[i+times] = array[i];
    for (int i = 0; i < times; i++) array[i] = temp[i];
    return array;
}

/*
Better Approach
---------------------
LOGIC - Loop for times, and every time while shifting every number to left send the first element of the array to the back.
TIME COMPLEXITY - O(N x K) Removes space but on worst case runs for very long.
SPACE COMPLEXITY - O(1)
*/

vector<int> left_rotation_better(vector<int> array, int times){
    int n = array.size();
    if ( n <= 1 ) return array;
    times = times % n;
    if (times == 0) return array;
    for (int i = 0; i < times; i++){
        int first = array[0];
        for (int j = 0; j < n-1; j++) array[j] = array[j+1];
        array.back() = first;
    }
    return array;
}

vector<int> right_rotation_better(vector<int> array, int times){
    int n = array.size();
    if ( n <= 1 ) return array;
    times = times % n;
    if (times == 0) return array;
    for (int i = 0; i < times; i++){
        int last = array.back();
        for (int j = n-1; j > 0; j--) array[j] = array[j-1];
        array[0] = last;
    } 
    return array;
}

/*
Optimal Approach
---------------------
LOGIC - reverse the part before the point of rotation , then reverse the rest part, then revese the whole array
TIME COMPLEXITY - O(2N) = O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> left_rotation_optimal(vector<int> array, int times){
    int n = array.size();
    if ( n <= 1 ) return array;
    times = times % n;
    if (times == 0) return array;
    
    reverse(array.begin(), array.begin()+times);
    reverse(array.begin()+times, array.end());
    reverse(array.begin(), array.end());

    return array;
}

vector<int> right_rotation_optimal(vector<int> array, int times){
    int n = array.size();
    if ( n <= 1 ) return array;
    times = times % n;
    if (times == 0) return array;
    
    reverse(array.end()-times, array.end());
    reverse(array.begin(), array.end()-times);
    reverse(array.begin(), array.end());

    return array;
}

int main() {
    // Check left rotation
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    vector<int> rotated_left = left_rotation_brute(vec, 3);
    for (auto it: rotated_left) cout << it << " ";
    cout << endl;

    // Check right rotation
    vector<int> vec2 = {1, 2, 3, 4, 5, 6};
    vector<int> rotated_right = right_rotation_brute(vec2, 3);
    for (auto it: rotated_right) cout << it << " ";
    cout << endl;
    return 0;
}