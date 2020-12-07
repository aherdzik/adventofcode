file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

parentToChildHolder = dict()

def evalBagCount(bagName, parentToChildHolder):
    result = 1
    for curTuple in parentToChildHolder[bagName]:
        result = result + (curTuple[0] * evalBagCount(curTuple[1], parentToChildHolder))
    return result

for line in Lines: 
    splitLine = line.split(" ")
    parentNode = splitLine[0] + splitLine[1]
    splitLine = splitLine[4:]
    parentToChildHolder[parentNode] = set()
    
    while len(splitLine) >=4:
        numberBags = int(splitLine[0])
        childNode = splitLine[1] + splitLine[2]
        tupleToAdd = (numberBags, childNode)
        parentToChildHolder[parentNode].add(tupleToAdd)
        splitLine = splitLine[4:]

count = 0
for curTuple in parentToChildHolder["shinygold"]:
    count = count + (curTuple[0] * evalBagCount(curTuple[1], parentToChildHolder))
print count