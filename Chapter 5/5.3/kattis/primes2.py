nCases = int(input())

bases = [2,8,10,16]

def gcd(a,b):
    if a > b:
        a,b = b,a
    if(a == 0):
        return b
    else:
        return gcd(b-a,a)

def is_prime(val:int) -> bool:
    if(val<=1):
        return False
    divisor = 2
    while(divisor * divisor <= val):
        if(val%divisor==0):
            return False
        divisor += 1
    return True

for _ in range(nCases):
    numer = 0
    denom = 0
    sVal = input()

    for base in bases:
        try:
            value = int(sVal,base)
            denom += 1

            if(is_prime(value)):
                numer+=1

        except (ValueError) as exp:
            pass
    if(denom==0):
        denom=1
    divisor = gcd(numer,denom)

    print(numer//divisor,"/",denom//divisor,sep='')
