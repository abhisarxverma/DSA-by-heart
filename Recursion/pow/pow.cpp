#include <iostream>
using namespace std;

// Loop

// This will cause Run time error - Time complexity - O(N)
int pow_loop_brute(int x, int n){

    double res = 1;

    for (int i = 1; i <= n; i++){
        res *= x;
    }

    if ( n < 0 ) res = (double)(1.0) / (double)(res);
    return res;

}

// Time complexity - O(Log N)
double pow_loop_optimal(int x, int n){

    double ans = 1.0;
    long long nn = n;
    if (nn<0) nn = -1 * n;
    while (nn) {
        if (nn % 2) {            // x^n = x * x^n-1
            ans = ans * x;
            nn = nn - 1;
        }
        else {
            x = x * x;          // x^n = (x^2)^n/2
            nn = nn / 2;
        }
    }
    if ( n < 0 ) ans = (double)(1.0) / (double)(ans);
    return ans;
}

// Recursion
// Time complexity - O(Log N)
// Space complexity - Recursion stack
double pow_recursive(double x, int n) {
    if (n == 0) return 1.0;

    if (n < 0) return 1.0 / pow_recursive(x, -n);

    if (n % 2 == 0) {
        double half = pow_recursive(x, n / 2);
        return half * half;                         // x^n = (x^n/2)^2
    }

    return x * pow_recursive(x, n - 1);             // x^n = x * x^n-1
}


int main(){
    int test = pow_loop_optimal(5, 3);
    cout << "Result :" << test << endl;
}