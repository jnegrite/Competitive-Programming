import sys

nCases = int(input())

fibAll = [[]]

for pwr in range(1,5):
    fib = [0, 1]

    k = 10**pwr
    while True:
        curr = fib[-1] + fib[-2]
        curr %= k
        if curr == 0 and fib[-1] == 1:
            break

        fib.append(curr)
    fibAll.append(fib)

for _ in range(nCases):
    a, b, n, m = tuple(map(int, input().split(' ')))
    
    p1, p2 = 0, 0

    if n == 0:
        p1 = 1
    else:
        fib = fibAll[m]
        md = n%len(fib)
        p1 = fib[md-1]
        p2 = fib[md]
    
    print((a * p1 + b * p2)%(10**m))
