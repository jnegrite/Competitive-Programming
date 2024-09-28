def getNextVal(value:int) -> int :
    if value%2 == 0:
        return value//2
    else:
        return value * 3 + 1

while True:
    data = list(map(int,input().split(' ')))
    if( data[0] == 0 and data[1]==0 ):
        break
    
    currSteps = 0
    currLoc = data.copy()
    memo = (dict(),dict())

    memo[0][data[0]] = 0
    memo[1][data[1]] = 0

    meetAt = -1
    finSteps = [-1,-1]

    if(data[0] == data[1]):
        meetAt = data[0]
        finSteps = [0,0]
        
    while meetAt == -1:
        #move items
        currSteps += 1
        for i in range(2):
            if(currLoc[i] == 1):
                continue

            currLoc[i] = getNextVal(currLoc[i])
            memo[i][currLoc[i]] = currSteps
    
        #check if in other map
        if currLoc[0] in memo[1].keys():
            meetAt = currLoc[0]
            finSteps = [currMemo[meetAt] for currMemo in memo]
        elif currLoc[1] in memo[0].keys():      
            meetAt = currLoc[1]
            finSteps = [currMemo[meetAt] for currMemo in memo]

    print(f"{data[0]} needs {finSteps[0]} steps, {data[1]} needs {finSteps[1]} steps, they meet at {meetAt}")
