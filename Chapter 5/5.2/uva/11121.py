nCases = int(input())

for tc in range(1,nCases+1):
    num = int(input())
    
    rems = []

    while num != 0:
        num, rem = divmod(num, -2)

        if rem < 0:
            rem+=2
            num+=1

        rems.append(rem)

    rems.reverse()
    if len(rems) == 0:
        rems.append(0)

    print("Case #", tc, ": ", ''.join([str(x) for x in rems]),sep='') 