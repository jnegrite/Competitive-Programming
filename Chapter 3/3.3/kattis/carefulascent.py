

def simulateSpeed(speed):
    x = 0
    y = 0
    for shield in shields:

        #get to that shield
        lb = shield.lowerBound
        x += (lb-y)*speed

        #simulate through that shildled
        x = shield.propagate(x,speed)
        y = shield.upperBound
    
    #get to the target height
    x += (yTarget-y)* speed

    return x

class Shield:
    lowerBound = 0
    upperBound = 0
    factor = 1.0
    height = 0

    def __init__(self,lowerBound,upperBound,factor):
        self.lowerBound=lowerBound
        self.upperBound=upperBound
        self.factor=factor
        self.height = upperBound-lowerBound

    def propagate(self, inputX, hVel):
        newVelocity = hVel * self.factor
        return inputX + self.height * newVelocity

xTarget, yTarget = tuple(map(int,input().split(" ")))

nShields = int(input())
shields = []
for i in range(nShields):
    data = input().split(" ")
    shields.append(Shield(int(data[0]), int(data[1]), float(data[2])))
shields.sort(key=lambda x: x.lowerBound)

ans = 0
low = 0
high = int(xTarget/yTarget)

if high == 0:
    if xTarget < 0:
        high = -2
    else:
        high = 2

if xTarget < 0:  
    low, high = high, low

if xTarget != 0:
    #get initial range
    while True:
        xLow = simulateSpeed(low)
        xHigh = simulateSpeed(high)

        if xLow <= xTarget <= xHigh:
            break

        if xTarget < xLow:
            low, high = low*2, low
        elif xTarget > xHigh:
            low, high = high, high * 2

    #do BSTA
    while True:
        mid = (low+high)/2

        xMid = simulateSpeed(mid)
        if(abs(xTarget-xMid) < 1e-6):
            ans = mid
            break

        if xTarget < xMid:
            high = mid
        elif xTarget > xMid:
            low = mid

print(ans)