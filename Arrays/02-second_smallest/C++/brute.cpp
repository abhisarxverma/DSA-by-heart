#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
Brute Force Approach
---------------------
INTUITION - Sort the array then give the second last element if any
TIME COMPLEXITY - O(N LOGN) - due to sorting
SPACE COMPLEXITY - O(N) - to store the sorted array
*/

int find_second_smallest_brute( vector<int> array ){
    sort(array.begin(), array.end());
    return array.size() > 1 ? array[array.size()-2] : NULL;
}

int main() {
    vector<int> vec = {5};
    cout << "Second smallest : " << find_second_smallest_brute(vec) << endl;
    return 0;

}