
def iterate(curr:tuple[int]) -> tuple[int]:
    output = [1]
    for i in range(1,len(curr)-1):
        output.append((output[-1] * curr[i+1] + 1)//curr[i])
    output.append(1)

    return tuple(output)

def main():
    while True:
        memo = dict()
        currGrid = []

        N = int(input())
        if N == 0:
            break

        tRow, tCol = tuple(map(int,input().split(' ')))
        tRow -= 1
        tCol -= 1

        currCol = 0
        curr = tuple(map(int, input().split(' ')))

        while tCol >= len(currGrid):
            if curr in memo:
                initPos = memo[curr]
                cycle = currCol - initPos
                tCol = ((tCol - initPos)%cycle)+initPos
                continue

            currGrid.append(curr)
            memo[curr] = currCol
            currCol += 1

            curr = iterate(curr)

        print(currGrid[tCol][tRow])

if __name__ == '__main__':
    main()
