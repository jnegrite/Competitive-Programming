from math import log2

def t7(limit:int, currVal: int):
    return currVal <= limit

def t6(limit:int, currVal:int):
    return currVal*log2(currVal) <= limit

def evalPow(limit:int, currVal: int, exponent:int):
    return (currVal**exponent) <= limit

def t5(limit: int, currVal:int):
    return evalPow(limit, currVal, 2)

def t4(limit: int, currVal:int):
    return evalPow(limit, currVal, 3)

def t3(limit: int, currVal:int):
    return evalPow(limit, currVal, 4)

def t2(limit: int, currVal: int):
    return currVal <= log2(limit)

def t1(limit: int, currVal:int, value:int):
    if currVal > limit:
        return False
    
    if value == 1:
        return True
    
    return t1(limit, currVal * value, value-1)


data = tuple(map(int, input().split(' ')))
limit = data[0]
value = data[1]
caseNum = data[2]

ans = False
match caseNum:
    case 1:
        ans = t1(limit,1,value)
    case 2:
        ans = t2(limit,value)
    case 3:
        ans = t3(limit, value)
    case 4:
        ans = t4(limit, value)
    case 5:
        ans = t5(limit, value)
    case 6:
        ans = t6(limit, value)
    case 7:
        ans = t7(limit, value)

if ans:
    print("AC")
else:
    print("TLE")