values = [int(x.strip()) for x in input().split(' ')[1:]]

data = [values]

#do processing
while(len(set(data[-1])) != 1):
    currLast = data[-1]
    data.append([x - currLast[i] for i,x in enumerate(currLast[1:])])

#propagate back
for i in range(len(data)-1,0,-1):

    data[i-1].append(data[i-1][-1] + data[i][-1])

print(f"{len(data)-1} {data[0][-1]}")
