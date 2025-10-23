from collections import defaultdict

nCases = int(input())

for _ in range(nCases):
    ans = 1

    nItems = int(input())
    counts = defaultdict(lambda: 1)

    for _ in range(nItems):
        _, typeName = input().strip().split(' ')
        counts[typeName] = counts[typeName] + 1
        
    ans = 1
    for v in counts.values():
        ans *= v
    print(ans-1)
