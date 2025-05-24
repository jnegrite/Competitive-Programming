import sys
import math

def ext_euclid(a, b):
    x, y = 1, 0
    xx, yy = 0, 1
    while b:
        q = a // b
        a, b = b, a % b
        x, xx = xx, x - q * xx
        y, yy = yy, y - q * yy
    return a, x, y

def main():
    t1, a1, b1 = map(float, sys.stdin.readline().split())
    t = int(round(t1 * 100))
    a = int(round(a1 * 100))
    b = int(round(b1 * 100))

    d, x0, y0 = ext_euclid(a, b)

    if t % d != 0:
        print("none")
        return

    ad = a // d
    bd = b // d
    td = t // d

    x0 *= td
    y0 *= td

    # Use float division for ceil/floor, but all variables are integers
    n1 = math.ceil(-x0 / bd)
    n2 = math.floor(y0 / ad)

    if n1 > n2:
        print("none")
    else:
        for n in range(n1, n2 + 1):
            print(f"{x0 + bd * n} {y0 - ad * n}")

if __name__ == "__main__":
    main()
