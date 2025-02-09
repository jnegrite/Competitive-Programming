
prime_factors = set()

def get_prime_factors(value: int, start: int):
    global prime_factors
    while start**2 <= value:
        if value%start == 0:
            prime_factors.add(start)
            get_prime_factors(value//start,start)
            return
        start += 1
    
    prime_factors.add(value)
    
while True:
    value = int(input())
    if(value == 0):
        break
    prime_factors.clear()
    get_prime_factors(value,2)
    
    for factor in prime_factors:
        value //= factor
        value *= (factor-1)
    print(value)
