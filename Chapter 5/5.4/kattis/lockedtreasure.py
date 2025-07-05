from math import comb

nCases = int(input())
for _ in range(nCases):
    n, m = map(int, input().split())
    print(comb(n,m-1))
