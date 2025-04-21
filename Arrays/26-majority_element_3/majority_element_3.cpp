#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// PROBLEM - Given an array, find the number which appears more than one-third of the size of the array

/*
 EXAMPLE INPUT - 2, 5, 2, 9, 2, 1
 EXAMPLE OUTPUT - 2
*/

/*
Brute Approach
---------------------
LOGIC - Loop over every element and then loop over the array again to get the count of the number of the outer loop
if the count is greater than the one-third of the array then return else pass. and if the majority element is not there
return -1

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

pair<int, int> majority_element_3_brute( vector<int> array ){
    int n = array.size();
    pair<int, int> ans = {-1, -1};
    for (auto num : array){
        int count = 0;
        for (auto num2 : array){
            if ( num2 == num ) count++;
        }
        if (count >= (n/3)+1){
            if (ans.first == -1) ans.first = num;
            else {
                if (num != ans.first) ans.second = num;
            }
        }

    }

    return ans;
}

/*
Better Approach
---------------------
LOGIC - Use a hashmap as a count storer, while iterating update the count in the hashmap and if the count
is greater than one-third of the size of the array return the number

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
*/

pair<int, int> majority_element_3_better( vector<int> array ){
    int n = array.size();
    pair<int, int> ans = {-1, -1};
    unordered_map<int, int> counter;
    for (auto num : array){
        counter[num]++;
        if (counter[num] >= (n/3)+1){
            if (ans.first == -1) ans.first = num;
            else {
                if (num != ans.first) ans.second = num;
            }
        }
    }
    return ans;
}

/*
Optimal Approach - BOYRE - MOORE'S VOTING ALGORITHM
-----------------------------------------------------
LOGIC - If you think carefully, you will see that there cannot exit more than 2 majority element 
if you want the count of the majority element to be more than one - third. so Unlike the normal 
boyre-moore's voting algorithm, this time take two variables as numbers and do the same as the normal
algorithm, increment if you find the same number and decrement if you find the different number
at last you should have the two majority elements in your two variables.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

pair<int,int> majority_element_3_optimal( vector<int> array ){
    vector<int> res;
    int element1 = INT_MIN;
    int element2 = INT_MIN;
    int count1 = 0;
    int count2 = 0;
    int min = (int) (array.size()/3)+1;

    for (int i = 0; i < array.size(); i++){
        if ( count1 == 0 && array[i] != element2){
            element1 = array[i];
            count1++;
        }
        else if ( count2 == 0 && array[i] != element1){
            element2 = array[i];
            count2++;
        }
        else if ( array[i] == element1 ) count1++;
        else if ( array[i] == element2 ) count2++;
        else {
            count1--; count2--;
        }
    }
    // We have to check manually if the result is true when the problem does not confidently says that there will always be the two majority element and if that's the case then the algorithm will give some random elements
    count1 = 0; count2 = 0;
    for (int i = 0; i < array.size(); i++){
        if ( array[i] == element1 ) count1++;
        else if ( array[i] == element2 ) count2++;
    }
    if ( count1 >= min ) res.push_back(element1);
    if ( count2 >= min ) res.push_back(element2);

    return {element1, element2};
}

int main() {
    vector<int> vec = {2, 2, 5, 5, 2, 5, 9, 5, 2};
    pair<int, int> majority_elements = majority_element_3_optimal(vec);
    cout << "Majority elements : " << majority_elements.first << " " << majority_elements.second << endl;
}
