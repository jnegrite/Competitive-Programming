import math

currVal = 1

v = input().strip()

isFound = False
for i in range(1,11):
    currVal *= i
    if(str(currVal) == v):
        isFound = True
        print(i)

if not isFound:
    targetLen = len(v)-1
    #do iteration
    currVal = math.log10(currVal)
    currAns = 10

    while int(currVal) < targetLen:
        currAns += 1
        currVal += math.log10(currAns)
    print(currAns)