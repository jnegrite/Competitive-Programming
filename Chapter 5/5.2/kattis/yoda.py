s1 = input()[::-1]
s2 = input()[::-1]

a1 = ""
a2 = ""

finLen = min(len(s1),len(s2))
for i in range(finLen):
    if s1[i] == s2[i]:
        a1 += s1[i]
        a2 += s2[i]
    elif s1[i] > s2[i]:
        a1 += s1[i]
    else:
        a2 += s2[i]

if len(s1) > finLen:
    a1 += s1[finLen:]

if len(s2) > finLen:
    a2 += s2[finLen:]

if len(a1) == 0:
    print("YODA")
else:
    print(int(a1[::-1]))

if len(a2) == 0:
    print("YODA")
else:
    print(int(a2[::-1]))
