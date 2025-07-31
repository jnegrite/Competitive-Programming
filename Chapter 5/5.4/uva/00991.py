from math import comb
from sys import stdin

def compute_catalan(n):
    n2 = 2*n
    return comb(n2,n) - comb(n2,n+1)

catalan = [1]

for n in range(1,21):
    catalan.append(compute_catalan(n))

inputs = [x.strip() for x in stdin.readlines()]
outputs = [str(catalan[int(x)]) for x in inputs if len(x) != 0]
print('\n\n'.join(outputs))
