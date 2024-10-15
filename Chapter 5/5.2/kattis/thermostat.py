from fractions import Fraction

nConversions, nQueries = map(int,input().strip().split(' '))

slopes = [Fraction.from_decimal(1)]
intercepts = [0]

for i in range(nConversions):
    v0, v100 = map(int, input().split(' '))
    intercepts.append(v0)
    slopes.append(Fraction(v100-v0,100))

for i in range(nQueries):
    x, y, v = map(int, input().split(' '))
    
    ans = ((v - intercepts[x])/slopes[x])*slopes[y] + intercepts[y]

    print(ans.numerator,'/',ans.denominator,sep='')
