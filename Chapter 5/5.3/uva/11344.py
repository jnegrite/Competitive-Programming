nCases = int(input())

def checkDivision(value, divisors) -> bool:
    for divisor in divisors:
        if value % divisor != 0:
            return False
    return True

for _ in range(nCases):
    M = int(input())
    divisors = list(map(int, input().split(' ')))[1:]

    ans = "Simple"
    
    if checkDivision(M, divisors):
        ans = "Wonderful"

    print(f"{M} - {ans}.")