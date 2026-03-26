
operators = ['+','*','%']

def convertRPN(values: list[str]):
    expr = []
    
    for value in values:
        if value in operators:
            p2 = expr.pop(-1)
            p1 = expr.pop(-1)

            expr.append(f'({p1}{value}{p2})')
        else:
            expr.append(value)

    return expr.pop(-1)

def main():
    while True:
        
        inputs = [x for x in input().split(' ') if x != '']
        N = int(inputs.pop(0))
        n = int(inputs.pop(0))

        if(N == 0):
            break

        expression = convertRPN(inputs)
        
        memo = dict()
        x = n
        currStep = 0

        while True:
            if x in memo:
                print(currStep - memo[x])
                break
            else:
                memo[x] = currStep
                x = eval(expression)
                currStep += 1

if __name__ == '__main__':
    main()
