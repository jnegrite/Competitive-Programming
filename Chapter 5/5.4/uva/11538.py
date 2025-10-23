while True:
    m, n = (map(int,input().split()))
    
    if m > n:
        m,n = n,m
    if m == 0 and n == 0:
        break

    ans = (m*n*(m+n-2))

    tmp_diag = (m-1)*((m-1)**2 -1)//3

    tmp_diag *= 2
    tmp_diag += (n-m+1) * m * (m-1)
    
    ans += tmp_diag*2
    print(ans)