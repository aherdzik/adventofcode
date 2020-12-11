file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def occupiedChairsInDirection(currentData,y,x, yDir, xDir, debugOn):
    if debugOn:
        print("looking at x: " ,x, " y: ", y, "xdir: ", xDir, " ydir: ", yDir)
    while y >= 0 and y <= len(currentData)-1 and x >= 0 and x <= len(currentData[y])-1 :
        if currentData[y][x] == 1:
            if debugOn:
                print("found empty chair")
            return 0
        elif currentData[y][x] == 2:
            if debugOn:
                print("found occupied chair")
            return 1
        x = x + xDir
        y = y + yDir     
    if debugOn:
        print("bounded out")
    return 0  

def countAdjacentSeats(currentData, y , x):
    toReturn = 0
    for lookY in range(-1,2):
         for lookX in range(-1,2):
            if lookX == 0 and lookY == 0:
                continue
            toReturn = toReturn + occupiedChairsInDirection(currentData, y+lookY , x+ lookX, lookY, lookX, False)
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
            elif currentData[y][x] == 2 and numAdjacentSeats >= 5:
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

def printFloor(currentData):
    for line in currentData:
        print(line)
    print(" ")
    
    
#printFloor(currentData)
currentData, changed = iterate(currentData)
while changed == True:
    #printFloor(currentData)
    currentData, changed = iterate(currentData)  
    
finalCount = 0
for finishedLine in currentData:
    for char in finishedLine:
        if char == 2:
            finalCount = finalCount + 1

print ("Final count: ",finalCount)   
