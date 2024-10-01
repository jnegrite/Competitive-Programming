import re
import sys
import math

for line in sys.stdin.readlines():
    ans = 0
    for m in re.finditer(r'\s+', line):
        ans = max(ans, math.ceil(math.log2(len(m.group()))))
    print(ans)