
memo = dict()

def get_oddbinom(value: int) -> int:
    global memo

    if value in memo:
        return memo[value]
    else:
        ans = 0
        if value <= 1:
            ans = value
        elif value%2 == 0:
            ans = 3 * get_oddbinom(value//2)
        else:
            lb = value//2
            ans = 2*get_oddbinom(lb) + get_oddbinom(lb+1)
        memo[value] = ans
        return ans

val = int(input())
print(get_oddbinom(val))