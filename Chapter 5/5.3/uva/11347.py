nCases = int(input())

primes = []

def generatePrimes():
    global primes
    primes = []
    
    isPrime = [True] * 1001
    for i in range(2,1000):
        if isPrime[i]:
            primes.append(i)
            for j in range(i*i,1001,i):
                isPrime[j] = False

def primeFactorize(value):
    factors = dict()

    for p in primes:
        if p*p > value:
            break

        numFactors = 0
        while value%p == 0:
            numFactors += 1
            value //= p
        
        if numFactors != 0:
            factors[p] = numFactors
    
    if value != 1:
        factors[value] = 1
    
    return factors

def getNumDiv(base, skip):
    numDiv = 1
    factors = dict()

    for f in range(base, 0, -skip):
        currFactors = primeFactorize(f)
        for cf in currFactors:
            if cf in factors:
                oldVal = factors[cf]
                numDiv //= (oldVal)

                oldVal += currFactors[cf]
                numDiv *= (oldVal)
                factors[cf] = oldVal
            else:
                factors[cf] = currFactors[cf] + 1
                numDiv *= factors[cf]

        if numDiv > 1e18:
            return 'Infinity'

    return numDiv

def main():
    generatePrimes()

    for tc in range(1,nCases+1):
        s = input().strip()
        idx = s.index('!')
        value = int(s[:idx])
        skip = len(s) - idx
        print("Case ",tc,": ", getNumDiv(value,skip),sep='')

if __name__ == "__main__":
    main()