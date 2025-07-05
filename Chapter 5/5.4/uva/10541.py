
# Memoization table size based on constraints
memo = [[-1 for _ in range(102)] for _ in range(202)]

def dp(rem_blocks, rem_positions):
    global memo
    if rem_blocks < 0 or rem_positions <= 0:
        return 0
    
    if memo[rem_blocks][rem_positions] != -1:
        return memo[rem_blocks][rem_positions]
    if rem_blocks == 0 or rem_positions == 1:
        memo[rem_blocks][rem_positions] = 1
        return 1
    
    memo[rem_blocks][rem_positions] = dp(rem_blocks-1, rem_positions) + dp(rem_blocks, rem_positions-1)
    return memo[rem_blocks][rem_positions]

def main():
    n_cases = int(input())

    for _ in range(n_cases):
        values = list(map(int, input().split()))
        n = values[0]
        k = values[1]
        
        n -= sum(values[2:])
        n -= (k-1)
    
        print(dp(n, k+1))

if __name__ == "__main__":
    main()
