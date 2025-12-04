
# BINARY TO DECIMAL CONVERSION
# Converting a base 2 number to base 10

# ITERATIVE 

def binary_to_decimal(bin: str) -> int:
    decimal = 0
    position = 1
    for bit in bin[::-1]:
        if int(bit):
            decimal += position
        position *= 2
    return decimal

# RECURSIVE 

def binary_to_decimal_recursive(bin: str, index: int=0) -> int:
    if index == len(bin): return 0
    bit = int(bin[index])
    return ((2 ** (len(bin)-index-1)) if bit else 0) + binary_to_decimal_recursive(bin, index+1)

# CHECK
print(binary_to_decimal("1010")) # -> 10
print(binary_to_decimal("1000")) # -> 8
print(binary_to_decimal_recursive("1010")) # -> 10
print(binary_to_decimal_recursive("1000")) # -> 8