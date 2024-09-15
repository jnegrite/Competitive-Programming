
borders = [
    ('0','9'),
    ('a','z'),
    ('A','Z'),
]

usedGroups = []
groups = []
groupLens = [10,26,26]

for low, high in borders:
    groups.append([chr(x) for x in range(ord(low), ord(high)+1)])

def getGroup(s:str) -> tuple:
    for i in range(3):
        if not s in groups[i]:
            continue

        idx = groups[i].index(s)
        if idx != -1:
            return i,idx
        
    return -1,-1

def add(s:str, val:int) -> str:
    ans = ""

    currGroup =  -1
    for ch in s[::-1]:
        if val == 0:
            ans = ch + ans
        else:
            grpInfo = getGroup(ch)
            currVal = grpInfo[1] + val
            currGroup = grpInfo[0]
            q, r = divmod(currVal,groupLens[currGroup])
            ans = groups[currGroup][r] + ans
            val = q

    while val > 0:
        q, r = divmod(val-1,groupLens[currGroup])
        ans = groups[currGroup][r] + ans
        val = q

    return ans

while True:
    try:
        s = input()
        vals = s.split(' ')
        usedGroups.clear()
        if(vals[0].isnumeric()):
            print(int(vals[0]) + int(vals[1]))
        else:
            print(add(vals[0],int(vals[1])))
    except EOFError:
        break