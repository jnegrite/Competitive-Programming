import sys

inputs = sys.stdin.read().splitlines()
idx = 0
while(True):
    num = int(inputs[idx])
    idx+=1
    if num==0:
        break

    b = 1
    hasAns = False
    while True:
        numer = num - 6*b*b
        if numer <= 0:
            break

        if(numer%(7*b)==0):
            hasAns = True
            a = numer//(7*b)
            print("Possible Missing Soldiers =",2*a*a)

        b+=1
    
    if hasAns == False:
        print("No Solution Possible")
    
    print("")