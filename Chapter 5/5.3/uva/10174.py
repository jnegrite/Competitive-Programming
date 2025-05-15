import sys

def check_bachelor(value):
    if value & 1:  # Check if the number is odd
        return False
    else:
        return (value & 2) != 0

def decompose(value) -> tuple[int,int]:
    p1 = 1
    if value%2 == 0:
        p1 = 2
    else:
        p1 = 1
    
    p2 = value//p1
        
    return ((p1+p2)//2,(p2-p1)//2)
    
def main():
    inputs = [[int(y) for y in x.strip().split(' ')] for x in sys.stdin.readlines()]
    for curr in inputs:
        if len(curr) == 1:
            if check_bachelor(curr[0]):
                print("Bachelor Number.")
            else:
                print(*decompose(curr[0]))
        else:
            p1 = curr[0]
            p2 = curr[1]

            p1 -= 1+((p1-3)%4)

            print((p2-p1)//4)

if __name__ == "__main__":
    main()

    