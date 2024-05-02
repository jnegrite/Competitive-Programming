
input()
numOptions = int(input())

#get options
data = []
ansGrid = []
for i in range(numOptions):
    data.append(input().split(", "))
    ansGrid.append([0] * numOptions)

for i in range(numOptions):
    temp = []
    for j in range(i+1,numOptions):
        diff = len([x for idx,x in enumerate(data[i]) if data[j][idx] != x])
        ansGrid[i][j] = diff
        ansGrid[j][i] = diff

numChanges = [max(x) for x in ansGrid]
minChanges = min(numChanges)
changesIdx = [i for i,x in enumerate(numChanges) if x == minChanges]

for i in changesIdx:
    print(", ".join(data[i]))