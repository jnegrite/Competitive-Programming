import sys

lines = sys.stdin.read().splitlines()
idx = 0
products = []

def getInput():
    global products, lines, idx
    ans = lines[idx]
    idx += 1
    return ans

def getProduct(valFrom:int, valTo:int) -> int:
    if 0 in values[valFrom:(valTo+1)]:
        return 0
    elif valFrom == 0:
        return products[valTo]
    elif products[valFrom-1] == 0:
        return products[valTo]
    else: 
        return products[valTo]//products[valFrom-1]


while idx < len(lines):
    values = []

    #read data
    while True:
        s=getInput().strip()
        temp = []
        if ' ' in s:
            temp = list(map(int,s.split(' ')))
        else:
            temp = [int(s)]
        if temp[-1] == -999999:
            temp.pop(-1)
            values.extend(temp)
            break
        else:
            values.extend(temp)

    products = [0] * len(values)

    currProduct = 1
    for i,x in enumerate(values):
        if x == 0:
            currProduct = 1
            products[i] = 0
        else:
            currProduct *= x
            products[i] = currProduct

    maxProduct = products[0]
    for valFrom in range(len(values)):
        for valTo in range(valFrom, len(values)):
            maxProduct = max(maxProduct,getProduct(valFrom,valTo))
    print(maxProduct,flush=True)
            