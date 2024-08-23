from math import sqrt, modf

nCases = int(input())
input()

while nCases > 0:
    nCases-=1

    #get home
    input()
    
    totalDist = 0.0

    #get paths
    while True:
        try:
            s = input()
        except EOFError: 
            break

        if len(s) == 0:
            break
            
        data = list(map(int,s.split(' ')))
        dx = (data[2] - data[0])/1000
        dy = (data[3] - data[1])/1000

        totalDist += sqrt(dx**2 + dy**2)
    
    #process
    totalDist /= 10
    minutes, hours = modf(totalDist)
    minutes = round(minutes * 60)
    hours = int(hours)

    if(minutes == 60):
        hours+=1
        minutes=0

    ans = "{}:{}".format(hours, str(minutes).zfill(2))
    
    print(ans)
    
    if nCases > 0:
        print("")
    else:
        break