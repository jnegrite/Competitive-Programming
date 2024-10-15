from fractions import Fraction

cases = int(input())
for tc in range(1,cases+1):
    nums = [int(x) for x in input().strip().split(' ') if x != ''][1:]

    ans = Fraction.from_decimal(0)
    for x in nums:
        ans += Fraction(1,x)
    ans = len(nums)/ans

    print("Case ", tc, ": ",ans.numerator,'/',ans.denominator,sep='')
