import sys

inputs = [set(x.strip().split(' ')) for x in sys.stdin.readlines()]

answers = []
for i in range(0,len(inputs),2):
    lA = len(inputs[i])
    lB = len(inputs[i+1])
    lI = len([x for x in inputs[i] if x in inputs[i+1]])

    ans = ""
    if lI == 0:
        ans = "A and B are disjoint"
    elif lA == lI:
        if lI == lB:
            ans = "A equals B"
        else:
            ans = "A is a proper subset of B"
    elif lB == lI:
        ans = "B is a proper subset of A"
    else:
        ans = "I'm confused!"
    
    answers.append(ans)

print('\n'.join(answers))
    