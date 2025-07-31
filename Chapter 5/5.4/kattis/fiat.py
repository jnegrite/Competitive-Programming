
md = 1000000007

def modPow(b, p, m):
    if(p==0):
        return 1
    ans = modPow(b,p//2,m)
    ans = (ans*ans)%m
    
    if p%2 == 1:
        ans = (ans*b)%m
    return ans

def inv(val:int):
    return modPow(val,md-2,md)

curr = 1
reps = int(input())
for i in range(reps):
    curr = ((4*i+2)%md * (curr)%md * inv(i+2))%md

print(curr)
