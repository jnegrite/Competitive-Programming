from sys import stdin
from collections import Counter

factorials = [1] * 101
for i in range(1,101):
    factorials[i] = factorials[i-1] *i

for word in stdin.readlines():
    word = word.strip()
    counts = Counter(word)
    
    value = factorials[len(word)]
    for k, v in counts.items():
        value //= factorials[v]
    print(value)
