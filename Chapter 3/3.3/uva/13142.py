


nCases = int(input())

f = [
    24 * 60 * 60,
    1000 * 1000
]
for tc in range(nCases):
    values = list(map(int,input().split(" ")))
    t = values[0] * f[0]
    s = values[1]
    d = values[2] * f[1]

    ans = int(d/t)
    if  ans > 0:
        print("Remove", ans, "tons")
    else :
        print("Add", abs(ans), "tons")
