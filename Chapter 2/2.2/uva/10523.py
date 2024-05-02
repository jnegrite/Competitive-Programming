import sys

inputs = sys.stdin.read().splitlines()

for s in inputs:
    n, a = map(int,s.split(" "))
    total = 0
    for i in range(1,n+1):
        total += (i * (a**i))
    print(total)