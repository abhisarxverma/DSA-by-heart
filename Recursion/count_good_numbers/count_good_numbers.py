

# Loop approach

# TIME COMPLEXITY - O( n x 10^n ) : O(10^n) for functools products getting combinations and O(n) for checking each digit in a combination
def count_good_numbers_loop(n: int) -> int:
    from itertools import product

    even_digits = ['0', '2', '4', '6', '8']
    prime_digits = ['2', '3', '5', '7']

    count = 0

    for digits in product('0123456789', repeat=n):

        is_good = True
        for i, d in enumerate(digits):
            if i % 2 == 0 and d not in even_digits:
                is_good = False
                break
            elif i % 2 == 1 and d not in prime_digits:
                is_good = False
                break

        if is_good:
            count += 1

    return count

# RECURSIVE APPROACH - for each index we will first put all the possible values in a loop and then we will call the function again to put the numbers further
# TIME COMPLEXITY - O(5^n/2 x 4*n/2) - we are going 5 level of depth for the even indexes and 4 level of depth for the odd indexes
def count_good_numbers_recursive(n: int) -> int:
    even_digits = ['0', '2', '4', '6', '8']
    prime_digits = ['2', '3', '5', '7']

    def dfs(index: int, current: str) -> int:
        if index == n:
            return 1

        count = 0
        allowed_digits = even_digits if index % 2 == 0 else prime_digits

        for digit in allowed_digits:
            count += dfs(index + 1, current + digit)

        return count

    return dfs(0, "")



# SIMPLE MATHS APPROACH - there can be only 5 numbers that we can put in even positions and there can be only 4 numbers that we can put in odd positions, so at last counting total combinations of both
# TIME COMPLEXITY - O(1)
def count_good_numbers_optimal(n: int) -> int:
    even_positions = (n + 1) // 2
    odd_positions = n // 2
    return (5 ** even_positions) * (4 ** odd_positions)


test = count_good_numbers_recursive(2)
print("Test result :", test)