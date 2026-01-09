from math import comb

def main():
    nCases = int(input())
    for _ in range(nCases):
        r,s,x,y,w = map(int,input().split(' '))
        
        if r <= 1:
            if w > 1:
                print("yes")
            else:
                print("no")
            continue

        #assume that x out of y throws are ok
        totalProb = 0
        cntOk = s-r+1
        cntFail = r-1
        currProb = cntOk**x * cntFail**(y-x)

        for cnt in range(x,y+1):
            totalProb+= currProb*comb(y,cnt)

            currProb//=cntFail
            currProb*=cntOk

        if totalProb*w > s**y:
            print("yes")
        else:
            print("no")

if __name__ == '__main__':
    main()
