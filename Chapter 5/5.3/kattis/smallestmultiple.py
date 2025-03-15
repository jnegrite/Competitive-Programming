import sys
from math import lcm

lines = [x.strip() for x in sys.stdin.readlines()]
for line in lines:
    print(lcm(*list(map(int,line.split(' ')))))
