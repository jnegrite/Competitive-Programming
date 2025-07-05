
sums = []
def create_triangle():
    global sums

    sums = [[1]]

    for _ in range(50):
        lst = sums[-1]
        nxt = [1]
        for i in range(1, len(lst)):
            nxt.append(lst[i-1]+lst[i])
        nxt.append(nxt[-1]+1)
        sums.append(nxt)

def main():
    global sums

    create_triangle()

    nCases = int(input())
    for _ in range(nCases):
        n, v1, v2, w = map(int,input().split())
        
        votes_to_win = n//2 + 1
        votes_remaining = (n-(v1+v2))

        if v1 + votes_remaining < votes_to_win:
            print("RECOUNT!")
        else:
            votes_needed = votes_to_win - v1
            if votes_needed <= 0 or \
                (100 * sums[votes_remaining][votes_remaining-votes_needed] / sums[votes_remaining][-1]) > w:
                print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
            else:
                print("PATIENCE, EVERYONE!")


if __name__ == '__main__':
    main()
