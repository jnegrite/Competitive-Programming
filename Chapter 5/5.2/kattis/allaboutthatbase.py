nCases = int(input())

def isValid(vars, base):
    try:
        v1 = 0
        v2 = 0
        v3 = 0
        if base == 1:
            for i in range(0,5,2):
                currSet = set(vars[i])
                if(len(currSet) != 1 or ('1' not in currSet)):
                    return False
            v1 = len(vars[0])
            v2 = len(vars[2])
            v3 = len(vars[4])

        else:
            v1 = int(vars[0],base)
            v2 = int(vars[2],base)
            v3 = int(vars[4],base)

        op = vars[1]
        expression = f"{v1} {op} {v2} == {v3}"

        return eval(expression)    
    except:
        return False

def encode(base):
    if base < 10:
        return chr(ord('0') + base)
    elif base == 36:
        return '0'
    else:
        return chr(ord('a') + (base-10))

for _ in range(nCases):
    ans = []
    curr = input().split(' ')
    for base in range(1,37):
        if(isValid(curr,base)):
            ans.append(encode(base))
    
    if len(ans) == 0:
        print("invalid")
    else:
        print("".join(ans))