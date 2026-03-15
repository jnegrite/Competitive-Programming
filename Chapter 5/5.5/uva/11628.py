from fractions import Fraction

while True:
    n, m = map(int, input().split(' '))
    if n == 0 and m == 0:
        break

    values = [0] * n

    for i in range(n):
        values[i] = int(input().split(' ')[-1])
    total = sum(values)

    for v in values:
        frac = Fraction(v,total)
        print(frac.numerator,'/',frac.denominator)