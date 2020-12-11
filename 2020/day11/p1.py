file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def countAdjacentSeats(currentData, y , x):
    toReturn = 0
    if y != 0:
        if x !=0 and currentData[y-1][x-1] == 2:
            toReturn = toReturn + 1
        if currentData[y-1][x] == 2:
            toReturn = toReturn + 1
        if x != len(currentData[y])-1 and currentData[y-1][x+1] == 2:
            toReturn = toReturn + 1
    if x !=0 and currentData[y][x-1] == 2:
        toReturn = toReturn + 1
    if x != len(currentData[y])-1 and currentData[y][x+1] == 2:
        toReturn = toReturn + 1
    if y != len(currentData)-1:
         if x !=0 and currentData[y+1][x-1] == 2:
            toReturn = toReturn + 1
         if currentData[y+1][x] == 2:
            toReturn = toReturn + 1
         if x != len(currentData[y])-1 and currentData[y+1][x+1] == 2:
            toReturn = toReturn + 1
            
    return toReturn

def iterate(currentData):
    changedResult = False
    newData = []
    for y in range(len(currentData)):
        lineToAdd = []
        for x in range(len(currentData[y])):
            numAdjacentSeats = countAdjacentSeats(currentData, y , x)
            if currentData[y][x] == 1 and numAdjacentSeats == 0:
                lineToAdd.append(2)
                changedResult = True
            elif currentData[y][x] == 2 and numAdjacentSeats >= 4:
                lineToAdd.append(1)
                changedResult = True
            else:
                lineToAdd.append(currentData[y][x])
        newData.append(lineToAdd)
    return newData, changedResult           

currentData = []
#0 is floor, 1 is chair, 2 is occupied
for line in Lines: 
    lineToAdd = []
    for l in line:
        if l == ".":
            lineToAdd.append(0)
        elif l == "L":
            lineToAdd.append(1)
    currentData.append(lineToAdd)
    
currentData, changed = iterate(currentData)
while changed == True:
    currentData, changed = iterate(currentData)  
    
finalCount = 0
for finishedLine in currentData:
    for char in finishedLine:
        if char == 2:
            finalCount = finalCount + 1

print ("Final count: ",finalCount)   
