import sys

fib = []

def generate_fib(cnt: int) -> list[int]:
    output = []
    p1, p2 = 1, 0

    for _ in range(cnt):
        curr = p1 + p2
        p1, p2 = curr, p1
        output.append(curr)

    return output

def fibi_to_dec(fibi:str) -> int:
    global fib
    return sum(fib[i] for i,x in enumerate(reversed(fibi)) if x=="1")

def dec_to_fibi(intVal: int) -> str:
    global fib

    output = ""
    for val in reversed([x for x in fib if x <= intVal]):
        if intVal >= val:
            output += "1"
            intVal -= val
        else:
            output += "0"

    if output == '':
        output = "0"
    return output

def main():
    global fib
    fib = generate_fib(110)
    
    inputs = [x.strip() for x in sys.stdin.readlines() if x != '\n']
        
    for i in range(0,len(inputs),2):
        if i > 0:
            print('')

        v1, v2 = inputs[i], inputs[i+1]
        print(dec_to_fibi(fibi_to_dec(v1) + fibi_to_dec(v2)))


if __name__ == '__main__':
    main()
