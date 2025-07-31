from math import comb, factorial


def compute_catalan(n):
    n2 = 2*n
    return comb(n2,n) - comb(n2,n+1)

while True:
    v = int(input())
    if v == 0:
        break
    print(compute_catalan(v)*factorial(v))
