from math import factorial


def catalan(val):
    return factorial(2*val)//(factorial(val+1) * factorial(val))

nValues = int(input())

cats = [0] * (nValues+1)
cats[0] = 1
for i in range(1,nValues+1):
    cats[i] = (2*(2*i-1)*cats[i-1])//(i+1)

ans = 0
low = 0
high = nValues
while low < high:
    ans += cats[low] * cats[high]
    low+=1
    high-=1

ans *= 2
if(low == high):
    ans += cats[low]**2

print(ans)
