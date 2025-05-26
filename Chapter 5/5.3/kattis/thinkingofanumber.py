from math import lcm

while True:
    lower_bound = 0
    upper_bound = None
    divisors = [1]

    nClues = int(input())
    if nClues == 0:
        break

    for _ in range(nClues):
        s = input()
        v = int(s.split(' ')[2])
        if s.startswith('greater than'):
            lower_bound = max(lower_bound,v)
        elif s.startswith('less than'):
            if upper_bound == None or v < upper_bound:
                upper_bound = v
        else:
            divisors.append(v)

    if upper_bound == None:
        print("infinite")
    else:
        m = lcm(*divisors)
        q, rem = divmod(lower_bound,m)

        if(rem == 0):
            lower_bound += m
        else:
            lower_bound += (m-rem)

        values = list(range(lower_bound,upper_bound,m))
        if len(values) == 0:
            print("none")
        else:
            print(' '.join([str(x) for x in values]))
