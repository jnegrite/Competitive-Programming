from math import factorial
import sys

super_catalan = [1,1]

p1 = 1
p2 = 1

for i in range(3,28):
    t = (3*(2*i-3) * p1 - (i-3) * p2)//i
    super_catalan.append(t)
    p1, p2 = t, p1

def catalan(val):
    return factorial(2*val)//(factorial(val+1) * factorial(val))

inputs = [int(x.strip()) for x in sys.stdin.readlines()]

for val in inputs:
    print(super_catalan[val-1] - catalan(val-1))
