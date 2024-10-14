import sys
from math import sqrt

inputs = [x.strip() for x in sys.stdin.readlines()]

nInputs = int(inputs.pop(0))

def divide(coefs:list, factor:float) -> list:
    ans = [coefs[0]]
    for i in range(1,len(coefs)-1):
        ans.append(ans[-1] * factor + coefs[i])
    return ans

for i in range(0,nInputs*3,3):
    coefs = [float(x) for x in inputs[i+1].split(' ')]
    factors = [float(x) for x in inputs[i+2].split(' ')]

    for f in factors:
        coefs = divide(coefs,f)
    
    a = coefs[0]
    b = coefs[1]
    c = coefs[2]

    prefix = -b/(2*a)
    disc = sqrt(b**2 - 4*a*c)/(2*a)

    print(round(prefix+disc,1))
    print(round(prefix-disc,1))
