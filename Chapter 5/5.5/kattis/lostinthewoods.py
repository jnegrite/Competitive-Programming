import random

nClearings, nPaths = map(int,input().split(' ' ))

neighbors = []
for _ in range(nClearings):
    neighbors.append([])

for _ in range(nPaths):
    a, b = map(int, input().split(' '))
    neighbors[a].append(b)
    neighbors[b].append(a)

#curr pos, curr len, curr prob

q = [(0,0)]

totalProb = 0
dctProbs = dict()

epsilon = 1e-10

dctProbs[(0,0)] = 1
ans = 0

while len(q) != 0:
    curr = q.pop(0)
    currProb = dctProbs[curr]
    currPos, currLen = curr

    if currPos == nClearings-1:
        totalProb += currProb

        ans += currLen * currProb
        continue
    
    nxtProb = currProb/len(neighbors[currPos])

    if nxtProb * (currLen+1) < epsilon:
        continue

    for neighbor in neighbors[currPos]:
        nxtCode = (neighbor,currLen+1)
        if nxtCode in dctProbs:
            dctProbs[nxtCode] += nxtProb
        else:
            dctProbs[nxtCode] = nxtProb
            q.append((neighbor,currLen+1))

print(f'{ans:.05f}')
