# DECIMAL TO BINARY CONVERSION
# Converting a base 10 number to base 2

# ITERATIVE 

def decimal_to_binary(n) -> str:
  res = ""
  while n > 0:
    res += str(n%2)
    n //= 2
  return res[::-1]

# RECURSIVE

def decimal_to_binary_recursive(n) -> str:
  if n <= 1: return str(n)
  return decimal_to_binary_recursive(n//2) + str(n%2)

# check
print(decimal_to_binary(10000)) # -> 10011100010000
print(decimal_to_binary(10)) # -> 1010
print(decimal_to_binary_recursive(1000)) # -> 1111101000
print(decimal_to_binary_recursive(5)) # -> 101