from math import sqrt

nCase = 1
while True:
    val = int(input())
    if val == 0:
        break

    print(f"Case {nCase}: {int((5+ sqrt(8*val + 1))/2)}")
    nCase += 1
