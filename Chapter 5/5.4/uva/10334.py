from sys import stdin

memo = []

def init_memo():
    global memo
    memo = []
    for nBounce in range(1001):
        tmpBounce = []
        for nPane in range(3):
            tmpBounce.append([-1,-1])
        memo.append(tmpBounce)

def dp(nBounce: int, nPane: int, nDir: int) -> int:
    global memo

    if nPane < 0 or nPane > 2:
        return 0

    ans = memo[nBounce][nPane][nDir!=1] 
    if ans != -1:
        return ans

    ans = 0
    
    if nBounce == 0:
        ans = 1
    
    elif (nPane == 0 and nDir == -1) or (nPane == 2 and nDir == 1):
        ans = dp(nBounce-1, 1, -nDir)
    else:
        ans = dp(nBounce-1,nPane-nDir, -nDir) + dp(nBounce, nPane+nDir, nDir)
    
    memo[nBounce][nPane][nDir!=1] = ans
    return ans

def main():
    global memo
    init_memo()

    for val in [int(x.strip()) for x in stdin.readlines()]:
        print(dp(val,0,1))

if __name__ == "__main__":
    main()




