import copy

file1 = open('input.txt', 'r') 

def findBounds(allData):
    xMin, yMin, zMin, wMin, xMax, yMax, zMax, wMax =  99999, 99999,99999, 99999, -999999, -999999, -999999, -9999999
    for x in allData.keys():
        for y in allData[x].keys():
            for z in allData[x][y].keys():
                for w in allData[x][y][z]:
                    if w < wMin:
                        wMin = w
                    if w > wMax:
                        wMax = w
                if z < zMin:
                    zMin = z
                if z > zMax:
                    zMax = z
            if y < yMin:
                yMin = y
            if y > yMax:
                yMax = y
        if x < xMin:
            xMin = x
        if x > xMax:
            xMax = x
                
    return xMin-1, yMin-1, zMin-1, wMin -1, xMax+1, yMax+1, zMax+1, wMax + 1    

def addPoint(x,y,z,w,data):
    if x not in data:
        data[x] = dict()
    if y not in data[x]:
        data[x][y] = dict()
    if z not in data[x][y]:
        data[x][y][z] = set()
    if w not in data[x][y][z]:
        data[x][y][z].add(w)

def checkPoint(x,y,z,w,data):
    return (x in data) and (y in data[x]) and (z in data[x][y]) and (w in data[x][y][z])

def numNeighbors(x,y,z,w,data):
    toReturn = 0
    for xVal in range(-1,2):
        for yVal in range(-1,2):
            for zVal in range(-1,2):
                for wVal in range(-1,2):
                    if xVal ==0 and yVal ==0 and zVal ==0 and wVal ==0:
                        continue
                    if checkPoint(x + xVal,y + yVal,z + zVal,w + wVal,data):
                        toReturn = toReturn + 1      
    return toReturn

def iterOnPoint(x,y,z,w, curData, newData):
    neighborCount = numNeighbors(x,y,z,w,curData)
    currentlyHasPoint = checkPoint(x,y,z,w,curData)
    if (currentlyHasPoint and (neighborCount == 2 or neighborCount == 3)) or (not currentlyHasPoint and neighborCount == 3):
        addPoint(x,y,z,w,newData)   
    
def cycleIt(allData):
    newData = dict()
    xMin, yMin, zMin, wMin, xMax, yMax, zMax, wMax = findBounds(allData)
    for xVal in range(xMin, xMax +1):
        for yVal in range(yMin, yMax +1):
            for zVal in range(zMin, zMax +1):
                for wVal in range(wMin, wMax +1):
                    iterOnPoint(xVal, yVal, zVal, wVal, allData, newData)
    return newData

y = 0
allData = dict()

for line in file1.readlines(): 
    for x in range(len(line)):
        if line[x] == "#":
            addPoint(x,y,0,0,allData)
    y = y + 1

for iterNum in range(6):
    allData = cycleIt(allData)
    
total = 0
for x in allData.keys():
    for y in allData[x].keys():
        for z in allData[x][y].keys():
            total = total + len(allData[x][y][z])
print(total)

    
