from sys import stdin

def main():
    fib = [0,1]
    p1, p2 = 1, 0,

    for _ in range(4999):
        curr = p1 + p2
        p1, p2 = curr, p1
        fib.append(curr)
    
    values = [int(x.strip()) for x in stdin.readlines()]
    for value in values:
        print(f"The Fibonacci number for {value} is {fib[value]}")

if __name__ == '__main__':
    main()