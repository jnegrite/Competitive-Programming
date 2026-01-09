from sys import stdin

inputs = [tuple(map(int,x.split(' '))) for x in stdin.readlines()]

memo = dict()

def dp(nFaces:int, remThrows:int, target:int) -> int:
    if target < 0:
        return 0

    if remThrows == 0:
        if target == 0:
            return 1
        else:
            return 0
        
    keyVal = (nFaces,remThrows,target)
    if keyVal in memo:
        return memo[keyVal]

    ans = 0
    for i in range(1,1+min(target,nFaces)):
        ans += dp(nFaces,remThrows-1,target-i)

    memo[keyVal] = ans
    return ans

for faces, throws, target in inputs:
    ans = dp(faces,throws,target)
    print(ans,faces**throws,sep='/')
