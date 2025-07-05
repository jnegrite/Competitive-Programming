from math import comb

while True:
    n, k = tuple(map(int, input().split()))
    if n == 0 and k == 0:
        break

    print(n,"things taken",k,"at a time is",comb(n,k),"exactly.")
