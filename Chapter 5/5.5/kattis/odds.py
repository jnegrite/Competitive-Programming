from fractions import Fraction

rank1 = [(1,2),(2,1)]
rank2 = [(i,i) for i in range(1,7)]

def compare(p1: tuple[int,int], p2: tuple[int,int]):
    if p1 in rank1:
        return p2 not in rank1
    elif p2 in rank1:
        return 0
    
    p11,p12 = p1
    p21,p22 = p2

    if p11 == p12:
        if p21 == p22 and p21 >= p11:
            return 0
        return 1
    
    if p21 == p22:
        return 0
    
    if p11 < p12:
        p12, p11 = p1
    
    if p21 < p22:
        p22, p21 = p2

    if p11 > p21:
        return 1
    elif p11 < p21:
        return 0
    else:
        return p12 > p22
    
def main():
    while True:
        values = [x.strip() for x in input().split(' ')]

        if(all(x=='0' for x in values)):
            break

        digits = []
        for value in values:
            if value == '*':
                digits.append([i for i in range(1,7)])
            else:
                digits.append([int(value)])
        
        p1 = []
        p2 = []

        for x in digits[0]:
            for y in digits[1]:
                p1.append((x,y))
        
        for x in digits[2]:
            for y in digits[3]:
                p2.append((x,y))
        
        total = 0
        for c1 in p1:
            for c2 in p2:
                total += compare(c1,c2)
        
        if total == 0:
            print(0)
        else:
            combinations = len(p1)*len(p2)
            if total == combinations:
                print(1)
            else:
                print(Fraction(total, len(p1) * len(p2)))
        
if __name__ == '__main__':
    main()
