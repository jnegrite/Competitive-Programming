from datetime import datetime, datedelta
while True:
    sInput = input()
    if sInput == "0 0 0 0":
        break

    data = list(map(int, sInput.split(' ')))
    dt = datetime(data[3], data[2],data[1])
    numYears = 400*(data[0]//146097)
    numDays = data[0]%146097
    dt += datedelta(years=numYears,days=numDays)
    print(f"{dt.day} {dt.month} {dt.year}")