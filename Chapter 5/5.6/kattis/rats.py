import re

def rats(v: int) -> int:
    sVal = str(v)
    vRev = int(sVal[::-1])
    return int(''.join(sorted(str(v + vRev))))

def check_creeper(value:int) -> bool:
    sVal = str(value)
    patterns = [r'^1233+4444$',r'^5566+7777$']
    for pattern in patterns:
        if re.match(pattern,sVal):
            return True
    return False

def main():
    nDatasets = int(input())
    for _ in range(nDatasets):
        dsNum, mTerms, seed = map(int,input().split(' '))

        idxRepeated = -1
        idxCreeper = -1
        seenValues = set([seed])

        if check_creeper(seed):
            idxCreeper = 1

        for idx in range(2,mTerms+1):
            newVal = rats(seed)

            if idxCreeper == -1 and check_creeper(newVal):
                idxCreeper = idx
            
            if idxRepeated == -1 and newVal in seenValues:
                idxRepeated = idx
            else:
                seenValues.add(newVal)    
            
            seed = newVal
            
        if idxCreeper != -1:
            print(dsNum, 'C', idxCreeper)
        elif idxRepeated != -1:
            print(dsNum, 'R', idxRepeated)
        else:
            print(dsNum, seed)

if __name__ == '__main__':
    main()
