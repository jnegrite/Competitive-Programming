import sys


def multipleOf17(s:str) -> bool:
    if(len(s) <= 3):
        return (int(s)%17)==0

    lastDigit = int(s[-1])
    temp = s[:-3]
    lastValues = int(s[-3:-1]) - (5 * lastDigit)
    while(lastValues < 0):
        lastValues += 17
    return multipleOf17(f"{temp}{lastValues:02d}")



inputs = sys.stdin.read().splitlines()

for s in inputs:
    if(s=="0"):
        break

    if multipleOf17(s):
        print(1)
    else:
        print(0)