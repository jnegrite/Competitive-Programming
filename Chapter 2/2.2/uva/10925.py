import sys

inputs = sys.stdin.readlines()

tc = 0
ln = 0
while True:
    N, F = map(int, inputs[ln].split(" "))
    ln += 1

    if N == 0 and F == 0:
        break

    total = 0
    for i in range(ln,ln+N):
        total += int(inputs[i])

    ln += N

    tc+=1
    print(f"Bill #{tc} costs {total}: each friend should pay {total//F}\n")

