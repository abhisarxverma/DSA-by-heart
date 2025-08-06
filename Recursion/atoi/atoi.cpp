#include <string>
#include <climits> 
using namespace std;

// Loop

int atoi_loop(const string& str) {
    const int lower_limit = INT_MIN; // lowest possible value for a 32 bit signed integer, one number less and the integer will overflow
    const int upper_limit = INT_MAX; // hightest possible value for a 32 bit signed integer, one number more and the integer will overflow

    bool make_negative = false;
    bool sign_seen = false;

    long long res = 0; 

    for (char ch : str) {

        // stop as soon as find first non digit character
        if (res != 0 && !isdigit(ch)) {
            break;
        }

        // stop of you find a character before finding any digit which not "+", "-" or " " and also not a digit
        if (res == 0 && ch != '-' && ch != '+' && ch != ' ' && !isdigit(ch)) {
            break;
        }

        // mark the make negative boolean flag true, if you find a "-"
        if (ch == '-' || ch == '+') {
            if (sign_seen) break;
            make_negative = (ch == '-');
            sign_seen = true;
            continue;
        }

        // if you find any digit character at this point, then simply add that in the result
        if (isdigit(ch)) {
            res = res * 10 + (ch - '0');

            // return lower limit if make negative flag is true and result corsses the lower boundary
            if (make_negative && -res < lower_limit) return lower_limit;
            // return upper limit if result crosses the boundry of upper limit
            if (!make_negative && res > upper_limit) return upper_limit;
        }
    }

    int final_result = make_negative ? -res : res;
    return final_result;
}

// Recursion


int atoi_recursion(const std::string& str, long long res = 0, size_t index = 0, bool make_negative = false, bool sign_seen = false) {
    if (index >= str.length()) return make_negative ? -res : res;

    char ch = str[index];

    if (res != 0 && !isdigit(ch)) return make_negative ? -res : res;
    if (res == 0 && ch != '-' && ch != '+' && ch != ' ' && !isdigit(ch)) return make_negative ? -res : res;

    if (ch == '-' || ch == '+') {
        if (sign_seen) return make_negative ? -res : res;
        make_negative = (ch == '-');
        sign_seen = true;
    }

    if (isdigit(ch)) {
        res = res * 10 + (ch - '0');
    }

    if (make_negative && -res < INT_MIN) return INT_MIN;
    if (!make_negative && res > INT_MAX) return INT_MAX;

    return atoi_recursion(str, res, index + 1, make_negative, sign_seen);
}
