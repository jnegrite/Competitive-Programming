import sys

inputs = [map(int,x.strip().split()) for x in sys.stdin.readlines()]

for cows, cars, shows in inputs:

    cowFirst = (cows)/(cows+cars) * (cars/(cows+cars-shows-1))
    carFirst = (cars)/(cows+cars) * (cars-1)/(cows+cars-shows-1)
    ans = cowFirst + carFirst
    print(f'{round(ans,5):.05f}')
