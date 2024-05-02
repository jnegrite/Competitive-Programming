import math

values = list(map(int,input().split(" ")))
d = values[0]/2
s = values[1]

def getLength(a):
    global d
    return 2*a*math.sinh(d/a)

low = d
high = 3000
while True:
    l = high + s
    r = high * math.cosh(d/high)
    if(l < r):
        low = high
        high *= 2
    else:
        break


while(abs(getLength(high)-getLength(low)) > 1e-7):
    mid = (low+high)/2
    l = mid + s
    r = mid * math.cosh(d/mid)

    if l < r:
        low = mid
    else:
        high = mid

print(round(2*low * math.sinh(d/low),7))
