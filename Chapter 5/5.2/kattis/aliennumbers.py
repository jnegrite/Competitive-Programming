nCases = int(input())

def decode(val:str, mapping:str) -> int:
    ans = 0
    base = len(mapping)

    multiplier = 1

    for ch in val[::-1]:
        idx = mapping.index(ch)
        ans += (multiplier * idx)

        multiplier *= base
    return ans

def encode(val:int,mapping:str) -> str:
    ans = ""

    if val == 0:
        return mapping[0]
    
    base = len(mapping)
    while val > 0:
        val, rem = divmod(val,base)
        ans = mapping[rem] + ans

    return ans

for tc in range(1,nCases+1):
    vals = list(input().split(' '))
    ans = encode(decode(vals[0],vals[1]),vals[2])

    print(f"Case #{tc}: {ans}")