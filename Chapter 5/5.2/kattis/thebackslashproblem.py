import re
import sys

inputs = [x.strip() for x in sys.stdin.readlines()]

for idx in range(0,len(inputs),2):
    levels = int(inputs[idx])
    buffer = "\\" * (2*(pow(2,levels)-1))
    strInput = inputs[idx+1]
    strInput = re.sub('([\!-\*\[-\]])',fr'{buffer}\1',strInput)
    print(strInput)
    
