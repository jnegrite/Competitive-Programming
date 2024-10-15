from math import gcd

tc = 0
while True:
    s = input().strip()
    if s == "-1":
        break

    tc += 1

    data = [x for x in s.split(' ') if x != '']
    numRep = int(data[0])
    s = data[1][2:]

    numer = int(s)
    denom = 10**(len(s))

    if numRep != 0:
        numer = int(s)
        numer -= (numer//(10**numRep))
        denom = 10**(len(s)) - 10**(len(s)-numRep)

    g = gcd(numer,denom)

    print("Case ",tc,": ",numer//g,"/",denom//g,sep='')
