#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


// LOOP APPROCH - get all possible nubmers which will be 10^n, and for each number put zero at start if needed and check if it satisfies the good number criteria
// TIME COMPLEXITY - O( n x 10^n ) : O(10^n) generating all possible numbers and O(n) for checking each digit in a combination
bool is_good_number(const string& digits) {
    const vector<char> even_digits = {'0', '2', '4', '6', '8'};
    const vector<char> prime_digits = {'2', '3', '5', '7'};

    for (size_t i = 0; i < digits.size(); ++i) {
        char d = digits[i];
        if (i % 2 == 0) {
            if (find(even_digits.begin(), even_digits.end(), d) == even_digits.end())
                return false;
        } else {
            if (find(prime_digits.begin(), prime_digits.end(), d) == prime_digits.end())
                return false;
        }
    }
    return true;
}

int count_good_numbers_loop(int n) {
    int count = 0;
    long long total = static_cast<long long>(pow(10, n));

    for (long long i = 0; i < total; ++i) {
        string digits = to_string(i);

        while (digits.length() < static_cast<size_t>(n)) {
            digits = '0' + digits;
        }

        if (is_good_number(digits)) {
            ++count;
        }
    }

    return count;
}

// RECURSIVE APPROACH - for each index we will first put all the possible values in a loop and then we will call the function again to put the numbers further
// TIME COMPLEXITY - O(5^n/2 x 4*n/2) - we are going 5 level of depth for the even indexes and 4 level of depth for the odd indexes
const vector<char> even_digits = {'0', '2', '4', '6', '8'};
const vector<char> prime_digits = {'2', '3', '5', '7'};

int dfs(int index, string current, int n){

    if (index == n) return 1;

    int count = 0;
    const vector<char> allowed_digits = index % 2 == 0 ? even_digits : prime_digits;

    for (char digit : allowed_digits) count += dfs(index + 1, current + digit, n);

    return count;
}

int count_good_numbers_recursive(int n){
    return dfs(0, "", n);
}


// SIMPLE MATHS APPROACH - there can be only 5 numbers that we can put in even positions and there can be only 4 numbers that we can put in odd positions, so at last counting total combinations of both
// TIME COMPLEXITY - O(1)
int count_good_numbers_optimal(int n){
    int even_positions = (n + 1) / 2;
    int odd_positions = n / 2;
    return (pow(5,even_positions)) * (pow(4, odd_positions));
}

int main() {
    int test = count_good_numbers_optimal(2);
    cout << "Test result :" << test << endl;
}