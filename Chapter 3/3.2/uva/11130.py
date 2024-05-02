import sys
import math

allInputs = sys.stdin.read().splitlines()[:-1]

for curr in allInputs:
    values = list(map(int,curr.split(" ")))

    a = values[0]
    b = values[1]
    v = values[2]
    A = values[3]
    s = values[4]

    totalDist = v*s/2

    dX = int(a/2 + totalDist * math.cos(math.pi * A/180))//a
    dY = int(b/2 + totalDist * math.sin(math.pi * A/180))//b

    print(dX, dY)