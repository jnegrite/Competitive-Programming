import sys

inputs = [list(map(int,x.strip().split(' '))) for x in sys.stdin.readlines()][:-1]
for row in inputs:
    q, r = divmod(row[0],row[1])
    print(f"{q} {r} / {row[1]}")
