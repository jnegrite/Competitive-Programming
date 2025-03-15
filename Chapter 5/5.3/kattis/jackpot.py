from math import lcm

nCases = int(input())
for _ in range(nCases):
    nWheels = int(input())
    wheelSizes = list(map(int, input().split(' ')))
    ans = lcm(*wheelSizes)

    if ans <= 1e9:
        print(ans)
    else:
        print("More than a billion.")