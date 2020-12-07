file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

childToParentHolder = dict()

for line in Lines: 
    splitLine = line.split(" ")
    parentNode = splitLine[0] + splitLine[1]
    splitLine = splitLine[5:]
    while len(splitLine) >=3:
        childNode = splitLine[0] + splitLine[1]
        if childNode not in childToParentHolder:
            childToParentHolder[childNode] = set()
        childToParentHolder[childNode].add(parentNode)
        splitLine = splitLine[4:]

shinyGoldParents = set()
onesToCheck = childToParentHolder["shinygold"]
currentList = list()
for current in onesToCheck:
    currentList.append(current)

while len(currentList) > 0:
    currentColor = currentList.pop()
    shinyGoldParents.add(currentColor)
    if currentColor in childToParentHolder:
        for newOnes in childToParentHolder[currentColor]:
            currentList.append(newOnes)
print(len(shinyGoldParents))