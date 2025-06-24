fib = [0,1]

n, k = (int(x) for x in input().split())

for i in range(2,n+1):
    fib.append(fib[-1] + fib[-2])

while n > 2:
    if k > fib[n-2]:
        k -= fib[n-2]
        n-=1
    else:
        n-=2

if n == 1:
    print("N")
else:
    print("A")