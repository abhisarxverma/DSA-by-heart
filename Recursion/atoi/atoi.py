
# Loop

def atoi_loop(string):
    lower_limit = -2147483648 # lowest possible value for a 32 bit signed integer, one number less and the integer will overflow
    upper_limit =  2147483647 # hightest possible value for a 32 bit signed integer, one number more and the integer will overflow

    make_negative = False

    sign_seen = False

    res = 0

    for char in string:

        # stop as soon as find first non digit character
        if res != 0 and not char.isdigit():
            break
        
        # stop of you find a character before finding any digit which not "+", "-" or " " and also not a digit
        if res == 0 and char not in ["-", "+", " "] and not char.isdigit():
            break

        # mark the make negative boolean flag true, if you find a "-"
        if char in ["-", "+"]:
            if sign_seen: break
            make_negative = (char == "-")
            sign_seen = True


        # if you find any digit character at this point, then simply add that in the result
        if char.isdigit():

            res *= 10
            res += int(char)

        # return lower limit if make negative flag is true and result corsses the lower boundary
        if make_negative and res*-1 < lower_limit:
            return lower_limit

        # return upper limit if result crosses the boundry of upper limit
        if res > upper_limit:
            return upper_limit

    return res*-1 if make_negative else res

# Recursion

def atoi_recursion(string, res=0, index=0, make_negative=False, sign_seen=False):

    if index >= len(string): return res*-1 if make_negative else res

    lower_limit = -2147483648 
    upper_limit =  2147483647 

    char = string[index]

    if res != 0 and not char.isdigit():
        return res*-1 if make_negative else res
    
    if res == 0 and char not in ["-", "+", " "] and not char.isdigit():
        return res*-1 if make_negative else res

    if char in ["-", "+"]:
        if sign_seen: return res*-1 if make_negative else res
        make_negative = (char == "-")
        sign_seen = True

    if char.isdigit():

        res *= 10
        res += int(char)

    if make_negative and res*-1 < lower_limit:
        return lower_limit

    if res > upper_limit:
        return upper_limit
    
    return atoi_recursion(string, res, index+1, make_negative=make_negative, sign_seen=sign_seen)

test = "  -29837"
ans = atoi_recursion(test)

print("Convert answer : ", ans)