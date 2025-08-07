
# Loop

# This will result in the Run time error cause this will take O(N) Time complexity
def pow_loop_brute(x: int, n: int):

    res = 1

    for _ in range(n):
        res *= x

    if (n < 0) : res = 1 / res

    return res

# Time complexity - O(Log N)
def pow_loop_optimal(x: int, n: int):

    ans = 1
    nn = n
    if n < 0: nn = -1 * n

    while nn:

        if nn % 2:
            ans *= x    # x^n = x * x^n-1
            nn -= 1
        else:
            x = x*x     # x^n = (x^2)^n/2
            nn /= 2

    if n < 0: ans = 1.0 / ans
    return ans

# Recursion
# Time complexity - O(Log N)
# Space complexity - Recursion Stack Space
def pow_recursion(x: int, n: int):

    if n == 0: return 1

    if n < 0: return pow_recursion(x, -n)

    if n % 2:
        return x * pow_recursion(x, n-1)   # x^n = x * x^n-1

    else:
        half = pow_recursion(x, n/2)    # x^n = (x^n/2)^2
        return half * half



test = pow_recursion(3, 5)
print("Pow result :", test)