def encode(val:int,mapping:str) -> str:
    ans = ""

    if val == 0:
        return mapping[0]
    
    base = len(mapping)
    while val > 0:
        val, rem = divmod(val,base)
        ans += mapping[rem]

    return ans

finMap = "0125689"

while True:
    try:
        val = input()

        ans = encode(int(val),finMap)
        ans = ans.replace('6','x')
        ans = ans.replace('9','6')
        ans = ans.replace('x','9')

        print(ans)
    except EOFError:
        break