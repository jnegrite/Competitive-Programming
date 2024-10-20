import math

while True:
    s = input()
    if s == "E":
        break
    
    temp = None
    dew = None
    hum = None

    data = s.split(' ')
    for i in range(0,3,2):
        if data[i] == 'T':
            temp = float(data[i+1])
        elif data[i] == 'D':
            dew = float(data[i+1])
        elif data[i] == 'H':
            hum = float(data[i+1])
    
    if dew is not None:
        e = 0.5555 * ((6.11 * math.exp( 5417.7530 * ((1/273.16) - (1/(dew + 273.16))))) - 10)
        if temp is not None:
            hum = temp + e
        else:
            temp = hum - e
    else:
        dew = (1/((1/273.16) - ((math.log((((hum - temp)/0.5555)+10)/6.11))/5417.7530)))-273.16

    print("T", round(temp,1),"D", round(dew,1),"H",round(hum,1))
