from math import gcd

values = [0] * 502

for i in range(1,501):
    for j in range(1,i):
        values[i] += gcd(i,j)

for i in range(1,501):
    values[i] += values[i-1]

while True:
    curr = int(input())
    if curr == 0:
        break
    
    print(values[curr])
