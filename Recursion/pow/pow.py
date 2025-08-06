
# Loop

# This will result in the Run time error cause this will take O(N) Time complexity
def pow_loop_brute(x: int, n: int):

    res = 1

    for i in range(n):
        res *= x

    return res

# Time complexity - O(Log N)
def pow_loop_optimal(x: int, n: int):

    res = 1
    power = n

    while power > 1:

        if power % 2 == 0:
            res *= x*x
            power //= 2
        else :
            res *= x
            power -= 1
    
    return res

# Recursion
# Time complexity - O(Log N)
# Space complexity - Recursion Stack Space
def pow_recursion(x: int, n: int, res:int = 1):

    if n <= 1: return res

    if n % 2 == 0:
        res *= x*x
        n //= 2
    else :
        res *= x
        n -= 1

    return pow_recursion(x, n, res)



test = pow_recursion(3, 5)
print("Pow result :", test)