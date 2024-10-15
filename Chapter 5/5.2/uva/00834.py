import sys

inputs = [[int(s) for s in x.strip().split(' ') if s != ''] for x in sys.stdin.readlines()]

for row in inputs:
    numer, denom = row

    ans = []
    while denom != 0:
        q, numer = divmod(numer,denom)
        ans.append(q)
        numer, denom = denom, numer
    
    print('[',ans[0],';',','.join(map(str,ans[1:])),']',sep='')
