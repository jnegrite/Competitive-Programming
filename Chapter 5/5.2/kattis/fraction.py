from fractions import Fraction

input()

class PartialFraction:
    terms = None
    frac = None

    def __init__(self,terms:list=None,frac:Fraction=None):
        if terms is not None:
            self.terms = terms
            self.decode()
        elif frac is not None:
            self.frac = frac
            self.encode()

    def decode(self) -> None:
        curr = Fraction(self.terms[-1],1)
        for v in self.terms[-2::-1]:
            curr = 1/curr
            curr += v
        
        self.frac=curr

    def encode(self) -> None:
        self.terms = []

        numer = self.frac.numerator
        denom = self.frac.denominator

        while denom != 0:
            q, numer = divmod(numer,denom)
            self.terms.append(q)
            numer, denom = denom, numer

    def __add__(self, o):
        return PartialFraction(frac=self.frac + o.frac)

    def __sub__(self, o):
        return PartialFraction(frac=self.frac - o.frac)

    def __mul__(self, o):
        return PartialFraction(frac=self.frac * o.frac)
    
    def __truediv__(self, o):
        return PartialFraction(frac=self.frac/o.frac)

    def __str__(self):
        return ' '.join(str(x) for x in self.terms)
    
q1 = [int(x) for x in input().strip().split(' ') if x != '']
q2 = [int(x) for x in input().strip().split(' ') if x != '']

pf1 = PartialFraction(q1)
pf2 = PartialFraction(q2)

print(pf1+pf2)
print(pf1-pf2)
print(pf1*pf2)
print(pf1/pf2)
