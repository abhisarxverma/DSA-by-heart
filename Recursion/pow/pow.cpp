#include <iostream>
using namespace std;


// Loop

// This will cause Run time error - Time complexity - O(N)
int pow_loop_brute(int x, int n){

    int res = 1;

    for (int i = 1; i <= n; i++){
        res *= x;
    }

    return res;

}

// Time complexity - O(Log N)
int pow_loop_optimal(int x, int n){

    int res = 1;
    int power = n;
    
    while (power > 1){

        if (power % 2 == 0){
            res *= x*x;
            power /= 2;
        }
        else {
            res *= x;
            power -= 1;
        }

    }
    return res;
}

// Recursion
// Time complexity - O(Log N)
// Space complexity - Recursion stack
int pow_recursion( int x, int n, int res = 1){

    if (n <= 1) return res;
    
    if (n % 2 == 0){
        res *= x*x;
        n /= 2;
    }
    else {
        res *= x;
        n -= 1;
    }
    
    return pow_recursion(x, n, res);
}

int main(){
    int test = pow_loop_optimal(5, 3);
    cout << "Result :" << test << endl;
}