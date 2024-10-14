import sys
from math import pow

def sumTo(x: int) -> int:
    return ((x)*(x+1))//2

def getAns(x:int) -> int:
    temp = sumTo(x)
    return str(temp * temp)

print('\n'.join([getAns(int(x.strip())) for x in sys.stdin.readlines()]))
