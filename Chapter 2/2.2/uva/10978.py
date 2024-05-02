
while True:
    numCards = int(input())
    if numCards == 0:
        break
    
    cards = [""] * numCards;
    nextCards = [i+1 for i in range(numCards)]
    nextCards[-1] = 0


    currPos = numCards-1
    prev = currPos

    for i in range(numCards):
        data = input()
        code = data[:2]
        word = data[3:]
        cnt = word
        for j in range(cnt):
            prev = currPos
            currPos = nextCards[currPos]
        cards[currPos] = code
        nextCards[prev] = nextCards[currPos]
    print(" ".join(cards))
