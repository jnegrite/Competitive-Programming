from math import prod
while True:
    values = list(map(int,input().split()))
    tmp = prod(values)*prod(values[-2:])
    if tmp == 0:
        break
    print(tmp)
