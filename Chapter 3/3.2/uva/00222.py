

target = 0
capacity = 0
mpg = 0
initCost = 0
minCost = 0
currCost = 0
nStations = 0
stations = []
currTank = 0
prevDist = 0

tc = 1

def backtrack(pos):
    global nStations, stations, capacity, mpg, currTank, currCost, minCost, prevDist
    dist, cost = stations[pos]
    if dist == target:
        if(minCost == 0 or currCost < minCost):
            minCost = currCost
        return
    
    #check if can opt not to fuel
    fuelRequired = (stations[pos+1][0] - dist)/mpg
    cacheTank = currTank
    
    if(currTank >= fuelRequired):
        #proceed without fueling
        currTank -= fuelRequired
        backtrack(pos+1)
        currTank = cacheTank
    
    
    cacheCost = currCost
    currCost += 2
    currCost += (capacity - currTank) * cost
    currTank = capacity - fuelRequired

    backtrack(pos+1)

    currCost = cacheCost
    currTank = cacheTank

while True:
    target = float(input())
    if target == -1:
        break

    capacity, mpg, initCost, nStations = tuple(map(float,input().split(" ")))
    nStations = int(nStations)
    stations = []
    stations.append((0,0))
    for i in range(nStations):
        a,b = tuple(map(float,input().split(" ")))
        stations.append((a,b/100))
    stations.append((target, 0))
    
    currTank = capacity
    currCost = initCost
    minCost = 0
    prevDist = 0

    backtrack(0)

    print("Data Set #",tc,sep='')
    print("minimum cost = ${:.02f}".format(minCost))
    tc+=1

