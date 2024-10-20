while True:
    nTerms = int(input())

    if nTerms==0:
        break

    values = []
    total = 0
    for i in range(nTerms):
        v = int(round(100*float(input()),0))
        values.append(v)
        total += v

    lower, rem = divmod(total,nTerms)
    upper = lower + 1
    
    above = 0
    below = 0
    
    for val in values:
        if val > upper:
            above += val-upper
        elif val < lower:
            below += lower-val
    
    print(f"${max(above,below)/100:.2f}")
