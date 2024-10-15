from math import gcd

while True:
    s = input().strip()
    
    if(s == '0'):
        break

    s = s[2:-3]
    fNumer = 1
    fDenom = 1
    baseDenom = 10**len(s)
    for i in range(1,len(s)+1):
        #i represents how many digits got repeated
        numer = int(s)
        numer -= (numer//(10**i))

        denom = baseDenom - 10**(len(s)-i)
        g = gcd(numer,denom)

        numer //= g
        denom //= g

        if (i == 1) or (denom < fDenom):
            fNumer = numer
            fDenom = denom

    print(fNumer,fDenom,sep='/')

