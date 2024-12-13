
ans = set()

#generate sieve
isPrime = [True] * 100
for i in range(2,100):
    if isPrime[i]:
        j = i*i
        while j < 100:
            isPrime[j] = False
            j += i

composites = [i for i,x in enumerate(isPrime) if not x]

MAX_VAL = 2**64-1
ans.add(1)
for base in range(2, 2**16 + 1):
    for power in composites:
        if base**power > MAX_VAL:
            break
        ans.add(base ** power)

fin_ans = sorted(list(ans))

for i in fin_ans:
    print(i)
