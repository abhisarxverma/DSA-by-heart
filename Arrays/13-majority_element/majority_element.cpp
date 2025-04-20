#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//MAJORITY ELEMENT - find the element that appears in the array more than half the size of the array

/*
Brute Force Approach
---------------------
LOGIC - Loop the array, and for every element, loop again to calculate it's count, if it is greater than
half the size of the array, return it else return -1;

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int majority_element_brute( vector<int> array ){
    int n = array.size();
    int target_count = (n/2)+1;
    for (auto num: array){
        int count = 0;
        for (auto num2: array){
            if (num == num2) count++;
        }
        if (count >= target_count) return num;
    }
    return -1;
}

/*
Better Approach
---------------------
LOGIC - Using a hashmap, to store the count while iterating, and to optimize a little, just after increasing count
of a number, we have to check if the target is met, else pass.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
*/

int majority_element_better( vector<int> array ){
    int n = array.size();
    int target_count = (n/2)+1;
    map <int, int> mpp;
    for (auto num : array){
        mpp[num]++;
        if (mpp[num] == target_count) return num;
    }
    return -1;
}

/*
Optimal Approach
---------------------
LOGIC - Boore-Moyre's voting algorithm, the concept is if a number has count greater than half the size
of array, then while iterating and increasing the count if we find the same number and descreasing the
count if we find other than that, then at last the number should be remaining, cause it is one extra than
half the size so no other can cancel out it.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int majority_element_optimal( vector<int> array ){
    int n = array.size();
    int number = array[0];
    int count = 1;
    for (int i = 1; i < n; i++){
        if (count == 0){
            number = array[i];
            count = 1;
        }
        else if (array[i] == number){
            count++;
        }
        else count--;
    }
    // If it is stated that the majority element may or may not exist then do a recheck
    int count2 = 0;
    for (auto it: array){
        if (it == number) count2++;
    }
    if (count2 >= (n/2)+1) return number;
    return -1;
}

// Check
int main()  {
    vector<int> vec = {1, 2, 1, 1, 1, 2};
    cout << "Majority element : " << majority_element_optimal(vec) << endl;
    return 0;
}