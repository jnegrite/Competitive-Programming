from math import factorial

memo = dict()

def catalan(val):
    if val in memo:
        return memo[val]
    else:
        ans = factorial(2*val)//(factorial(val+1) * factorial(val))
        memo[val] = ans
        return ans

nValues = int(input())
for _ in range(nValues):
    print(catalan(int(input())))
