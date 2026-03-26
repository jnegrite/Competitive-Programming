
def getNext(a, b, curr, N):
    return (a * (curr**2) + b)%N

def main():
    while True:
        
        values = list(map(int, [x for x in input().split(' ') if x != '']))
        if values[0] == 0:
            break

        N = values[0]
        a = values[1]
        b = values[2]
        curr = 0
        currSteps = 0

        memo = dict()
        while True:
            if curr in memo:
                print(N - (currSteps-memo[curr]))
                break
            else:
                memo[curr] = currSteps
                currSteps+=1
                curr = getNext(a,b,curr,N)
        
if __name__ == '__main__':
    main()