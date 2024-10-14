import sys
from math import sqrt

inputs = [x.strip() for x in sys.stdin.readlines()]

def calculateVal(val: float, coefs:list) -> float:
    ans = 0
    
    currFactor = 1
    for coef in coefs:
        ans += currFactor * coef
        currFactor *= val
    return ans

for i in range(0,len(inputs),2):
    bottom = [float(x) for x in inputs[i].split(' ')]
    top = [-float(x) for x in inputs[i+1].split(' ')]
    
    combi = [bottom[i] + top[i] for i in range(len(bottom))]
    derivative = [i*x for i,x in enumerate(combi)][1:]
    a = derivative[-1]
    b = derivative[-2]
    c = derivative[-3]

    prefix = -b/(2*a)
    disc = b*b - 4*a*c

    peaks = [0,1]
    if(disc >= 0):
        disc = sqrt(disc)/(2*a)
        for f in [-1,1]:
            x = prefix + f*disc
            if x > 0 and x < 1:
                peaks.append(x)
    values = [calculateVal(x, combi) for x in peaks]
    print(round(max(values) - min(values),7))