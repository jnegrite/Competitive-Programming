while True:
    s = input()
    if s == "0 0 0 0":
        break

    sp = s.split(" ")

    loanAmt = int(sp[0])
    pmt = float(sp[1])
    periods = 12*int(sp[2])
    pct = float(sp[3])/1200

    if pct == 0:
        if pmt * periods >= loanAmt:
            print("YES")
        else:
            print("NO")
        continue

    component = (1+pct)**periods
    reqPmt = loanAmt * (pct * component) / (component-1)

    if pmt >= reqPmt:
        print("YES")
    else:
        print("NO")