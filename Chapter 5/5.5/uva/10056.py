nCases = int(input())

for _ in range(nCases):
    values = [x for x in input().split(' ') if x != '']
    nPlayers = int(values[0])
    prob = float(values[1])
    idxFin = int(values[2])
    ans = 0

    if prob == 1:
        if idxFin == 1:
            ans = 1
        else:
            ans = 0
    elif prob == 0:
        ans = 0
    else:
        curr = (1-prob)**(idxFin-1)
        step = (1-prob)**nPlayers
        ans = (curr * prob)/(1-step)

    print(f'{ans:0.4f}')