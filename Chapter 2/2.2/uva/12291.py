
n = 0
m = 0
grid = []
subGrid = []

def getTopLeft(grid:list) -> tuple:
    for i,row in enumerate(grid):
        for j,col in enumerate(row):
            if col == "*":
                return (i,j,True)
    return (-1,-1,False)

def inGrid(row:int, col:int):
    global n
    return 0 <= row < n and 0 <= col < n

def isValid() -> bool :
    global n,m,grid,subGrid

    markers = []
    isFound = False
    subGridTL = (-1,-1,False)
    for i,row in enumerate(subGrid):
        for j,col in enumerate(row):
            if col == "*":
                if not isFound:
                    isFound = True
                    subGridTL = (i,j,True)
                
                markers.append((i-subGridTL[0], j-subGridTL[1]))
    
    if not subGridTL[2]:
        return False

    gridTL = getTopLeft(grid)
    if not gridTL[2]:
        return False
    
    #first removal
    for marker in markers:
        tempRow = gridTL[0] + marker[0]
        tempCol = gridTL[1] + marker[1]

        if not inGrid(tempRow,tempCol):
            return False

        if grid[tempRow][tempCol] != "*":
            return False

        grid[tempRow][tempCol] = "." 

    gridTL = getTopLeft(grid)
    if not gridTL[2]:
        return False
    
    #second removal
    for marker in markers:
        tempRow = gridTL[0] + marker[0]
        tempCol = gridTL[1] + marker[1]

        if not inGrid(tempRow,tempCol):
            return False

        if grid[tempRow][tempCol] != "*":
            return False

        grid[tempRow][tempCol] = "." 

    #making sure nothing was left
    for row in grid:
        for col in row:
            if col == "*":
                return False

    return True

while True:
    n, m = map(int,input().split(" "))
    if n==0 and m==0:
        break

    grid = []
    subGrid = []

    for row in range(n):
        grid.append(list(input()))
    
    for row in range(m):
        subGrid.append(list(input()))

    if isValid():
        print(1)
    else:
        print(0)