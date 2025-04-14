import sys

factorials = [1]
for i in range(1,51):
    factorials.append(factorials[-1]*i)

for data_in in sys.stdin.readlines():
    n, k = map(int,data_in.split(' '))
    digits = list(range(1,n+1))
    ans = []

    while len(digits) != 0:
        q, k = divmod(k, factorials[len(digits)-1])
        ans.append(str(digits.pop(q)))
    print(' '.join(ans))