import sys

inputs = [x.strip() for x in sys.stdin.readlines()]

iCtr = 0
while iCtr < len(inputs):
    currNum = inputs[iCtr]
    iCtr += 1

    while(currNum[-1] != '#'):
        currNum += inputs[iCtr]
        iCtr += 1

    currNum = int(currNum[:-1],2)
    if currNum % 131071 == 0:
        print("YES")
    else:
        print("NO")