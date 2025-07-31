from math import comb
from sys import stdin

def compute_catalan(n):
    n2 = 2*n
    return comb(n2,n) - comb(n2,n+1)

catalan = dict()

n = 1
while True:
    cat = compute_catalan(n)

    if cat > 5e9:
        break
    else:
        catalan[cat] = n
        n += 1

inputs = [int(x.strip()) for x in stdin.readlines()]
for value in inputs:
    print(catalan[value])
