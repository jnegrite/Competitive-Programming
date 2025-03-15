from math import gcd

while True:
    s = input()

    if s=="0":
        break

    values = sorted(map(int, s.split(' ')))
    values.remove(0) 
    subtracted = [x - values[0] for x in values[1:]]
    print(gcd(*subtracted))