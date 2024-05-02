import sys

solutions = []

class Input:
    data = []
    idx = 0

    def __init__(self):
        self.data = sys.stdin.read().splitlines()
        self.idx = 0
    
    def input(self) -> str:
        if(self.idx < len(self.data)):
            ans = self.data[self.idx]
            self.idx += 1
            return ans
        return None

input = Input()

statements = []
mapInvolved = {}
involved = []

configs = [
    "evil",
    "divine",
    "human",
    "human",
]

timeConfigs = [
    "day",
    "night",
]

def validateConfig() -> bool:
    global statetements, mapInvolved
    for st in statements:
        speaker = st[0]
        subject = st[1]
        negate = False
        object = st[-1]

        if(st[3] == "not"):
            negate = True

        if(object == "lying"):
            if st[2] == "am":
                #for the contradiction
                if not negate:
                    return False
            else:
                if(mapInvolved[speaker] == "evil" or
                        (mapInvolved[speaker] == "human" and mapInvolved["It"] == "night")):
                    negate = not negate                

                status = (mapInvolved[subject] == "evil" or
                        (mapInvolved[subject] == "human" and mapInvolved["It"] == "night"))

                status = (status != negate)                
                if status == False:
                    return False
            continue

        if(mapInvolved[speaker] == "evil" or
                (mapInvolved[speaker] == "human" and mapInvolved["It"] == "night")):
            negate = not negate

        status = ((mapInvolved[subject] == object) != negate)        
        if status == False:
            return False
    return True
        
def backtrack(pos:int):
    global involved, mapInvolved, configs, solutions
    if(pos == len(involved)):
        if(validateConfig()):
            #print(mapInvolved)
            solutions.append(mapInvolved.copy())
        return

    if(pos==-1):
        for tm in timeConfigs:
            mapInvolved["It"] = tm
            backtrack(pos+1)
        return

    for config in configs:
        mapInvolved[involved[pos]] = config
        backtrack(pos+1)

def printSolution() -> None:
    global solutions, involved
    if(len(solutions) == 0):
        print("This is impossible.")
        return
    
    factFound = False
    involved.append("It")
    for curr in involved:
        outputs = list(set([x[curr] for x in solutions]))
        if(len(outputs) == 1):
            factFound = True
            print(curr," is ",outputs[0],".",sep='')
    
    if not factFound:
        print("No facts are deducible.")

s = input.input()
convNum = 1
while s != "0":
    numLines = int(s)
    
    statements = []
    involved = set()

    for i in range(numLines):
        s = list(input.input().split(" "))
        s[0] = s[0][:1]
        if(s[1] == "I"):
            s[1] = s[0]
        involved.add(s[0])
        if(s[1] not in ["I","It"]):
            involved.add(s[1])
        
        s[-1] = s[-1][:-1]
        statements.append(s)

    involved = sorted(list(involved))
    solutions.clear()


    print("Conversation #",convNum,sep='')
    convNum+=1

    backtrack(-1)
    printSolution()
    print("")

    s = input.input()