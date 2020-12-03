file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

currentData = []
width = 0
for line in Lines: 
    toStore = []
    width = len(line)
    for i in line:
        if i == ".":
            toStore.append(False)
        elif i == "#":
            toStore.append(True)
    currentData.append(toStore)

count = 1

def CheckSlope(xDelta, yDelta):
    currentY = 0
    currentX = 0
    toReturn = 0
    while currentY < len(currentData):
        if currentData[currentY][currentX % width] == True:
            toReturn = toReturn + 1
        currentY = currentY + yDelta
        currentX = currentX + xDelta
    return toReturn

slopesToCheck = [[1,1],[3,1],[5,1],[7,1],[1,2]]

for slope in slopesToCheck:
    count = count * CheckSlope(slope[0], slope[1])

print(count)  