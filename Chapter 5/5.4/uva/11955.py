import re

coef = [[0 for _ in range(51)] for _ in range(51)]
coef[0][0] = 1

for row in range(1,51):
    coef[row][0] = 1
    for col in range(1, row+1):
        coef[row][col] = coef[row-1][col-1] + coef[row-1][col]

nCases = int(input())
for tc in range(1,nCases+1):
    expression = input()

    m = re.match(r'\((.+)\+(.+)\)\^(.+)',expression)
    term1, term2, exponent = m.groups()
    exponent = int(exponent)
    terms = []
    for p2 in range(exponent + 1):
        p1 = exponent - p2

        curr = ''
        currCoef = coef[exponent][p1]
        if(currCoef != 1):
            curr += f'{currCoef}*'
        
        if p1 > 0:
            curr += term1
            if p1 > 1:
                curr += f'^{p1}'
        
        if p1 > 0 and p2 > 0:
            curr += '*'
        
        if p2 > 0:
            curr += term2
            if p2 > 1:
                curr += f'^{p2}'
        terms.append(curr)
    print(f"Case {tc}: {'+'.join(terms)}")
